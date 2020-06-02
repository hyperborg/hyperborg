#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject *parent) : QObject(parent),
unicore_thread(NULL), unicore(NULL),
coreserver(NULL), coreserver_thread(NULL),
beacon(NULL), beacon_thread(NULL), _parser(NULL), _guimode(false),
role(Undecided)
{
    log(0, "NODECORE intialized");
    _requiredfeatures = Standard;
    _appmode = appmode;
    _requestedMatrixId = 0;	// Matrix id we want to join by default
    settings = HSettings::getInstance();

    QObject::connect(&checknodebin_timer, SIGNAL(timeout()), this, SLOT(checkNodeBinary()));
    checknodebin_timer.start(2000);
    checknodebin_timer.setSingleShot(false);
}

NodeCore::~NodeCore()
{
}

void NodeCore::launch()
{
}

void NodeCore::loadPlugins()
{
    // Loading all plugins rom the 'plugins' subdirectory. Only the ones matching activePlugins() are actually tried
    slot_log(Info, "Plugin load started");
    QStringList namefilters;
    namefilters << "*.so" << "*.dll";
    QDir pluginsDir("plugins");
    const auto entryList = pluginsDir.entryList(namefilters, QDir::Files);
    for (const QString &fileName : entryList)
    {
    if (activePlugins().contains(fileName))
    {
        PluginSlot *pluginslot = new PluginSlot(this);
        if (pluginslot->initializePlugin(pluginsDir.absoluteFilePath(fileName)))
        {
        pluginslots.append(pluginslot);
        }
        else
        {
        pluginslot->deleteLater();
        }
        }
    }
    slot_log(Info, "Plugin loading ends");

    // We loaded what we could load. Now we define whether we run in console or GUI mode (needed for QApplication creation)
    for (int i=0;i<pluginslots.count();++i)
    {
    _requiredfeatures |= pluginslots.at(i)->requiredFeatures();
    log(0, QString::number(i) + " " + pluginslots.at(i)->pluginName() + " " + QString::number(pluginslots.at(i)->requiredFeatures()));
    }
}

void NodeCore::launchGUI()
{
	_guimode = true;
	launchApplication();
}

void NodeCore::launchConsole()
{
	launchApplication();
}

void NodeCore::launchApplication()
{
    log(0, "Launch NodeCore with guimode: " + QString::number(_guimode));
    init();
    if (_guimode)
    {
        basepanel = new BasePanel();
        QObject::connect(this, SIGNAL(logLine(QString)), basepanel, SLOT(slot_logLine(QString)));
        // just dump all the loglines that was created before
        for (int i = 0; i < logpuffer.count(); i++)
        {
            basepanel->slot_logLine(logpuffer.at(i));
        }
        basepanel->show();
    }
    connectPlugins();
    initPlugins();

    // initialize networking 

    mastertimer = new QTimer(this);
    mastertimer->setSingleShot(true);
    QObject::connect(mastertimer, SIGNAL(timeout()), this, SLOT(mastertimer_timeout()));
    settings = HSettings::getInstance();
    matrixid = settings->value(Conf_MatixId).toString();
    role = settings->value(Conf_NodeRole).toInt();		// might need mapping for user readable config!
    port = settings->value(Conf_Port).toInt();
    wsocket = new CoreSocket();

    switch (role)
    {
        case Undecided:
            log(0, "First run. Waiting for matrix echoes");
            mastertimer->start(5000);	// 5 secs
            break;
        case Slave:
            log(0, "We are slave, waiting for master IP on port "+QString::number(port));
            joinNetwork(matrixid, role, port);
            break;
        case Master:
            // The node has existing configuration from previous runs. So we just set and launch up immediately.
            // It would be easier to set the master's IP address from configuration, but we could never be suer
            // that the all IPs are fixed and not moving. (Consider dynamic IP addresses from DHCP) So we still rely
            // in Beacon infrastructure to collect connection information.
            log(0, "We are the master of matrixid: "+matrixid+", setting up beacon on port "+QString::number(port));
            break;
        default:
            break;
    }
}

void NodeCore::connectPlugins()
{
    for (int i=0; i<pluginslots.count(); i++)
    {
        log(0, "Connect plugin: " + QString::number(i));
		pluginslots.at(i)->connectPlugin();
    }
}

void NodeCore::initPlugins()
{
    for (int i=0; i<pluginslots.count(); i++)
    {
        log(0, "Init plugin: " + QString::number(i));
		pluginslots.at(i)->initPlugin();
    }
}

void NodeCore::log(int severity, QString logline)
{
    slot_log(severity, logline);
}

void NodeCore::slot_log(int severity, QString logline)
{
    slot_log("", severity, logline);
}

void NodeCore::slot_log(QString source, int severity, QString logline)
{
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    QString logstr = dt.toString("yyyy.MM.dd hh:mm:ss.zzz") + " [" + QString::number(severity) + "] " + logline;
    logpuffer << logstr;
    if (logpuffer.length() > 10000)
    {
        logpuffer.removeFirst();
    }
    qDebug() << logstr;
    emit logLine(logstr);
}

void NodeCore::setCMDParser(QCommandLineParser *parser)
{
    _parser=parser;
    if (!parser) return;

    // This is the main place where we are decising a lot of thing about how to behave
    // What we are deciding here is accessible for all plugins (in read only mode of course)


    if (_parser->isSet("config"))
    {
        QString config = _parser->value("config");
        log(0, "use different config: " + config);
        if (!config.isEmpty())
        {
            settings->useSettings(_parser->value(config));
        }
    }

    if (_parser->isSet("role"))
    {
        QString tval = _parser->value("role").toUpper();
        log(0, "presetting role: " + role);
        if (tval=="MASTER" || tval=="SLAVE")
        {
            settings->setValue(Conf_NodeRole, tval);
        }
    }
    if (_parser->isSet("matrix"))
    {
        QString tval = _parser->value("matrix");
        log(0, "presetting matrix: " + tval);
        settings->setValue(Conf_MatixId, tval);
    }
/*
    if (_parser->isSet("f"))
    {
    qDebug() << "Foreground is set";
    settings->setValue("NodeCore", "foreground", "true");
    }

    if (_parser->isSet("no-gui"))
    {
    qDebug() << "disable GUI mode";
    settings->setValue("NodeCore", "disable_gui", "true");
    }
*/
    if (_parser->isSet("remotehost"))
    {
        QString rh = _parser->value("remotehost");
        log(0, "Presetting remote master node: " + rh);
        settings->setValue("NodeCore", "remote_host", rh);
        log(0, "Turn beacon off, using remote host: " + rh);
        if (_parser->isSet("remote_port"))
        {
            QString rp = _parser->value("port");
            log(0, "Using different port for the connection: " + rp);
            settings->setValue("remote_port", rp);
        }
    }

    // One of the most important thing is in which matrix we want to be the part of
}

QByteArray NodeCore::getBinaryFingerPrint(QString filename)
{
    QByteArray retarray;
    QFile bf(qApp->arguments().at(0));
    if (bf.open(QIODevice::ReadOnly))
    {
	    retarray = QCryptographicHash::hash(bf.readAll(), QCryptographicHash::Md5);
	    bf.close();
    }
    return retarray;
}

void NodeCore::init()
{
    // Generate fingerprint from the executed binary file
    if (qApp->arguments().count()) // should be always true
	node_binary_fingerprint = getBinaryFingerPrint(qApp->arguments().at(0));
//    log(0, "Node binary fingerprint: " + QString(node_binary_fingerprint));
    log(0, "Node binary fingerprint is stored");

    unicore=new UniCore();
    unicore_thread = new QThread(this);
    unicore->moveToThread(unicore_thread);

    QString servername = "hyperborg-node";
    coreserver = new CoreServer(servername, QWebSocketServer::NonSecureMode, 33333); // for now. We add certs handling later
    coreserver_thread = new QThread();
    coreserver->moveToThread(coreserver_thread);

    beacon = new Beacon();
    beacon_thread=new QThread();
    beacon->moveToThread(beacon_thread);
    QObject::connect(beacon, SIGNAL(logLine(int, QString)), this, SLOT(slot_log(int, QString)));

    bool f= QObject::connect(beacon, SIGNAL(matrixEcho(QString, QString, QString, QString, int)),
        this, SLOT(matrixEcho(QString, QString, QString, QString, int)));

    unicore_thread->start();
    beacon_thread->start();
    coreserver_thread->start();

    QMetaObject::invokeMethod(unicore, "init");
    QMetaObject::invokeMethod(beacon, "init");
    QMetaObject::invokeMethod(coreserver, "init");

}

// connectServices is where we query all loaded plugins what they provide or accept. This builds up the node's 
// featrue table that would be dispatched and collected by the master later on to make instruction deploy plannable

void NodeCore::connectServices()
{
    for (int i=0;i<pluginslots.count();i++)
    {
    }
}

/* checkNodeBinary && restartnode

    The following functions are a bit drastic, since they are not shutting
    down the node properly, yet. The main reason for the existence for these
    function at this moment is to support the building and testing of the nodes.

*/

void NodeCore::checkNodeBinary()
{
    if (!qApp->arguments().count()) return;
    QByteArray cb = getBinaryFingerPrint(qApp->arguments().at(0));
    if (cb!=node_binary_fingerprint)
    {
        log(0, "Node binary has been changed. Restarting.");
	    restartNode();
    }
}

void NodeCore::restartNode()
{
    // clean up connection and release resources
    log(0, "RESTART");
    qApp->exit(NODE_RESTART_CODE);
}

/* ------ NETWORK DISCOVERY AND MESH INITIALIZATIO -------------  */

void NodeCore::matrixEcho(QString matrixid, QString nodeid, QString noderole, QString ip, int port)
{
    if (noderole == "MASTER")
    {
        // we found a node controlling a matrix matrix
        if (matrixid == this->matrixid)
        {
            if (role == Master)
            {
                // CONFLICT - handling needed -> should log this issue on both nodes
            }
            else if (role == Slave)
            {
                // Connect
                connect("", ip, port);
            }
            else if (role == Undecided)
            {
                // We connect to this one. We still can instruct master to set our matrix id to
                // something different
            }
        }
    }
    else if (noderole == "SLAVE")
    {
        // we could use this node to query info about master that might be temporary down
        // or busy. This info could be hijacked (like someone installs and presets a node with false
        // information! We will get over this with mutual authentication as well as limiting installattion
        // window. For now we are not doing anything
    }
}

void NodeCore::mastertimer_timeout()
{
    if (role != Undecided) return;
    // At this point we have looked around the local network, but no matrix signature was present
    // Also loading from configuration file, we could override
    role = Master;
    matrixid = settings->value(Conf_MatixId).toString();
    int port = settings->value(Conf_Port).toInt();
    log(0, "No matrix echo on the network. Promoted to be the master of Matrix: " + matrixid + " on port " + QString::number(port));
    joinNetwork(matrixid, role, port);
}

void NodeCore::joinNetwork(QString _matrixid, int _role, int _port)
{
    settings->setValue(Conf_NodeRole, role); // mapping!
    settings->setValue(Conf_MatixId, matrixid);
    settings->setValue(Conf_Port, port);
  
    // spin up beacon to attract nodes coming up later
    beacon->setMatrixAndRole(matrixid, "MASTER");
    beacon->setSelectedMatrix(port, matrixid);
}

void NodeCore::connect(QString id, QString ip, int port)
{
    if (!wsocket) return;
    if (wsocket->state() == QAbstractSocket::ConnectedState)
    {
        wsocket->disconnect();

    }
}


