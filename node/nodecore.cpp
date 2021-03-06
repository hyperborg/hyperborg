#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject *parent) : QObject(parent),
unicore(NULL),
coreserver(NULL), coreserver_thread(NULL),
beacon(NULL), beacon_thread(NULL), _parser(NULL), _guimode(false),
 wsocket(NULL), mastertimer(NULL), logpuffer_used(true)
{
#if HTEST   // delete log file at each startup to ease debugging
    QFile f(QDir::homePath() + "/hyperborg.log");
    if (!f.remove())
    {
        log(0, "hyperborg.log file cannot be removed!");
    }
#endif

    int id = qRegisterMetaType<NodeCoreInfo>("NodeCoreInfo");
    log(0, "===============================================================================================");
    log(0, QString("HYPERBORG NODE STARTUP version: %1   build: %2").arg(HYPERBORG_VERSION).arg(HYPERBORG_BUILD_TIMESTAMP));
    log(0, "===============================================================================================");
    _requiredfeatures = Standard;
    _appmode = appmode;
    _requestedMatrixId = 0;	// Matrix id we want to join by default
    settings = HSettings::getInstance();

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

    QStringList pluginsdir;

#ifdef _MSC_VER         //TODO: plugin .dll location should be transferred out from x64/* dirs to keep them clean 
#ifdef _DEBUG
    pluginsdir << "x64/Debug";
#else
    pluginsdir << "x64/Release";
#endif
#endif

#ifdef LINUX
    pluginsdir << ".";
#endif

#ifdef WASM
    // WebAssembly currently not supporting dynamic libraries (it can load modules though)
#endif

    for (int i = 0; i < pluginsdir.count(); i++)
    {
        QDir pluginsDir(pluginsdir.at(i));
        log(0, QString("Checking for plugin in directory: %1").arg(pluginsDir.absolutePath()));
        const auto entryList = pluginsDir.entryList(namefilters, QDir::Files);
        for (const QString& fileName : entryList)
        {
            PluginSlot* pluginslot = new PluginSlot(this);
            if (pluginslot->initializePlugin(pluginsDir.absoluteFilePath(fileName)))
            {
                log(0, QString("Initialized plugin: %1").arg(fileName));
                pluginslots.append(pluginslot);
            }
            else
            {
                log(0, QString("Discarded plugin: %1").arg(fileName));
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
        QObject::connect(this, SIGNAL(logLineHUD(QString)), basepanel, SLOT(slot_logLineHUD(QString)));                     // sending generated log to HUD
        QObject::connect(basepanel, SIGNAL(logLine(int, QString, QString)),this, SLOT(slot_log(int, QString, QString)));    // receiving log elements from HUD for processing
        basepanel->show();
	    basepanel->setSlotter(slotter);
        for (int i = 0; i < logpuffer.count(); i++)     // push all loglines to HUD log window what was puffered before
        {
            emit logLineHUD(logpuffer.at(i));
        }
        logpuffer.clear();
        logpuffer_used = false;
    }
    connectPlugins();
    initPlugins();
    initNetworking();

    // starting up binary/config file change watching
    QObject::connect(&checknodebin_timer, SIGNAL(timeout()), this, SLOT(checkNodeBinary()));
    checknodebin_timer.start(60000);
    checknodebin_timer.setSingleShot(false);
    QStringList wlist;
    wlist << QDir::currentPath();
    wlist << "/usr/local/hyperborg";    // fixed for WASM tests
    log(0, tr("Tracking directory ") + wlist.at(0) + tr(" for changes"));
    watcher = new QFileSystemWatcher(wlist, this);
    QObject::connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(checkNodeBinary(QString)));
    QObject::connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(checkNodeBinary(QString)));
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

void NodeCore::slot_log(int severity, QString logline, QString source)
{
    if (source.isEmpty()) source = "CORE";
    QDateTime dt;
    dt = QDateTime::currentDateTime();
    QString logstr = dt.toString("yyyy.MM.dd hh:mm:ss.zzz") + "["+QString::number(severity)+"]" +" (" + source + ") " + logline;
    if (logpuffer_used)
    {
        logpuffer.append(logstr);
    }
    emit logLineHUD(logstr);

    QFile f(QDir::homePath() + "/hyperborg.log");
    if (f.open(QIODevice::Append))
    {
        logstr += "\n";
        QTextStream stream(&f);
        stream << logstr;
        f.close();
    }
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
        log(0, "presetting role: " + nodeinfo.noderole);
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
    if (_parser->isSet("gui"))
    {
        log(0, "setting forced GUI mode");
        settings->setValue(Conf_GUI, true);
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
    log(0, "Node binary fingerprint is stored");

    // Creating main modules
    log(0, "Creating main modules");
    // -- BEACON --
    beacon = new Beacon();
    beacon_thread = new QThread();
    beacon->moveToThread(beacon_thread);
    QObject::connect(beacon, SIGNAL(logLine(int, QString, QString)), this, SLOT(slot_log(int, QString, QString)));
    QObject::connect(this, SIGNAL(setRole(NodeCoreInfo)), beacon, SLOT(setRole(NodeCoreInfo)));
    QObject::connect(beacon, SIGNAL(matrixEcho(NodeCoreInfo)), this, SLOT(matrixEcho(NodeCoreInfo)));

    // -- CORESERVER --
    QString servername = "hyperborg-node";
    log(0, "Creating coreserver");
    coreserver = new CoreServer(servername, QWebSocketServer::SecureMode, 33333);
//    coreserver = new CoreServer(servername, QWebSocketServer::NonSecureMode, 33333); // for now. We add certs handling later
    coreserver_thread = new QThread();
//    coreserver->moveToThread(coreserver_thread);
    QObject::connect(this, SIGNAL(setupCoreServer(NodeCoreInfo)), coreserver, SLOT(setup(NodeCoreInfo)));
    QObject::connect(coreserver, SIGNAL(logLine(int, QString, QString)), this, SLOT(slot_log(int, QString, QString)));
    QObject::connect(this, SIGNAL(setRole(NodeCoreInfo)), coreserver, SLOT(setRole(NodeCoreInfo)));
    QObject::connect(this, SIGNAL(connectToRemoteServer(QString, QString)), coreserver, SLOT(connectToRemoteServer(QString, QString)));

    // -- UNICORE --
    log(0, "Creating unicore");
    unicore = new UniCore();
    QObject::connect(unicore, SIGNAL(logLine(int, QString)), this, SLOT(slot_log(int, QString)));
    QObject::connect(this, SIGNAL(setRole(NodeCoreInfo)), unicore, SLOT(setRole(NodeCoreInfo)));
    unicore->setCSSidePackBuffer(ind_buffer);

    // -- SLOTTER --
    log(0, "Creating slotter");
    slotter = new Slotter();
    QObject::connect(slotter, SIGNAL(logLine(int, QString, QString)), this, SLOT(slot_log(int, QString, QString)));

    // Creating buffers
    log(0, "Creating buffers");
    ind_buffer = new PackBuffer(unicore->getWaitCondition());     // Coreserver->Unicore buffer
    outd_buffer = new PackBuffer(NULL);                           // Unicore->Coreserver buffer
    inp_buffer = new PackBuffer(slotter->getWaitCondition());     // Unicore->Slotter buffer
    outp_buffer = new PackBuffer(unicore->getWaitCondition());    // Slotter->Unicore buffer

    // CoreServer initial buffers
    log(0, "Set CS initial buffer");
    coreserver->setInboundBuffer(ind_buffer);
    coreserver->setOutbountBuffer(outd_buffer);

    // datapaths between CoreServer<->UniCore
    log(0, "Building datapaths between CS<->UC");
    unicore->setCSSidePackBuffer(ind_buffer);
    QObject::connect(coreserver, SIGNAL(incomingData(DataPack*)), ind_buffer, SLOT(addPack(DataPack*)));
    QObject::connect(unicore, SIGNAL(newPackReadyForCS(DataPack*)), outd_buffer, SLOT(addPack(DataPack*)));
    QObject::connect(outd_buffer, SIGNAL(newData()), coreserver, SLOT(newData()));

    // datapatsh between UniCore<->Slotter
    log(0, "Building datapaths between UC<->slotter");
    unicore->setSLSidePackBuffer(outp_buffer);
    QObject::connect(unicore, SIGNAL(newPackReadyForSL(DataPack*)), inp_buffer, SLOT(addPack(DataPack*)));
    QObject::connect(slotter, SIGNAL(newPackReady(DataPack*)), outp_buffer, SLOT(addPack(DataPack*)));
    slotter->setInboundBuffer(inp_buffer);

    // Initialize all main modules
    log(0, "Initialize all modules");
    QMetaObject::invokeMethod(unicore, "init");
    QMetaObject::invokeMethod(beacon, "init");
    QMetaObject::invokeMethod(coreserver, "init");
    QMetaObject::invokeMethod(slotter, "init");

    // Adding system module entities to slotter
//??    slotter->registerEntity(coreserver->getEntity());
//??    slotter->registerEntity(unicore->getEntity());
//??    slotter->registerEntity(slotter->getEntity());

    // Launch threads, start executing
    log(0, "Start modules (threaded execution)");
    log(0, "Starting beacon");
    beacon_thread->start();

    log(0, "Starting coreserver");
    coreserver_thread->start();

    log(0, "Starting unicore");
    unicore->start();

    log(0, "Starting slotter");
    slotter->start();

    // Loading all plugins
    // Currently all plugins should be pushed up to the slotter. We do not have any low level driver yet
    for (int i=0;i<pluginslots.count();i++)
    {
        slotter->addPluginSlot(pluginslots.at(i));
    }
    slotter->activatePlugins();

//    saveConfiguration();    // for testing: creating valid configuration
    loadConfiguration();
}

// LoadConfiguration stops all layers, clear execution stacks and all modules
// are forced to reload configuration
void NodeCore::loadConfiguration()
{
    QStringList cfgs;
    cfgs << "config_imi.json";       // Load the configuration file it finds first
    cfgs << "config.json";
    QJsonParseError parseError;
    bool parsed = false;

    for (int i = 0; i < cfgs.count() && !parsed; i++)
    {
        QFile cfgf(cfgs.at(i));
        if (cfgf.open(QIODevice::ReadOnly))
        {
            QByteArray cfgdata = cfgf.readAll();
            QJsonDocument jsonDoc(QJsonDocument::fromJson(cfgdata, &parseError));
            if (parseError.error==QJsonParseError::NoError)
            {
                QJsonValue json_global  = jsonDoc["global"];
                if (json_global.isObject())
                {
                    // process configuration for nodeCore
                }
                QJsonValue json_beacon  = jsonDoc["beacon"];
                if (json_beacon.isObject())
                {
//                    if (beacon) beacon->setConfiguration(json_beacon.toObject());     // not yet implemented
                }
                QJsonValue json_unicore = jsonDoc["unicore"];
                if (json_unicore.isObject())
                {
  //                  if (unicore) unicore->setConfiguration(json_unicore.toObject());   // not yet implemented
                }
                QJsonValue json_slotter = jsonDoc["slotter"];
                if (json_slotter.isObject())
                {
                    if (slotter)
                    {
                        QJsonObject lobj = json_slotter.toObject();
                        slotter->loadConfiguration(lobj);
                    }
                }

                parsed = true;
            }
            else
            {
                log(0, QString("While opening configuration file [%1] JSON parsing error happened: %2").arg(cfgs.at(i)).arg(parseError.errorString()));
            }
        }
    }
}

void NodeCore::saveConfiguration()
{
    QString cfg = "config.ini";
    QJsonObject root;
    QJsonObject json_beacon;
//    if (beacon) beacon->getConfiguration(json_beacon);    // not yet implemented
    root["beacon"] = json_beacon;

    QJsonObject json_unicore;
    //    if (beacon) beacon->getConfiguration(json_beacon);    // not yet implemented
    root["unicore"] = json_unicore;

    QJsonObject json_slotter;
    if (slotter) slotter->saveConfiguration(json_slotter);    // not yet implemented
    root["slotter"] = json_slotter;

    QByteArray ba = QJsonDocument(root).toJson();
    QFile f(cfg);
    if (f.open(QIODevice::WriteOnly))
    {
        f.write(ba);
        f.close();
    }

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

void NodeCore::checkNodeBinary(const QString& str)
{
    checkNodeBinary();
}

void NodeCore::restartNode()
{
    // clean up connection and release resources
    log(0, "RESTART");
    qApp->exit(NODE_RESTART_CODE);
}

/* ------ NETWORK DISCOVERY AND MESH INITIALIZATION -------------  */
void NodeCore::initNetworking()
{
   nodeinfo.matrixid = settings->value(Conf_MatixId).toString();
    nodeinfo.noderole = settings->value(Conf_NodeRole).toString();		// might need mapping for user readable config!
    nodeinfo.port = settings->value(Conf_Port).toString();
    nodeinfo.ip = settings->value(Conf_IP).toString();


#ifdef WASM  // in WASM mode node is always slave and we always read the remote address and port from the invoking html
    nodeinfo.noderole = NR_SLAVE;
    emit setRole(nodeinfo);
    nodeinfo.ip=QString(emscripten_run_script_string("document.getElementById('hyperborg_params').getAttribute('remote_server');"));
    nodeinfo.port=QString(emscripten_run_script_string("document.getElementById('hyperborg_params').getAttribute('remote_port');"));
    log(0, QString("This node is slave, connecting to remote server %1 on port %2").arg(nodeinfo.ip).arg(nodeinfo.port));
    emit connectToRemoteServer(nodeinfo.ip, nodeinfo.port);
#else
    if (nodeinfo.noderole == NR_UNDECIDED)
    {
        emit setRole(nodeinfo);
        log(0, "First run. Waiting for matrix echoes");
        if (!mastertimer)
            mastertimer = new QTimer(this);
        mastertimer->setSingleShot(true);
        QObject::connect(mastertimer, SIGNAL(timeout()), this, SLOT(mastertimer_timeout()));
//#ifndef HDEBUG
        mastertimer->start(5000);	// 5 secs
//1#endif
    }
    else if (nodeinfo.noderole == NR_SLAVE)
    {
        log(0, QString("This node is slave, connecting to remote server %1 on port %2").arg(nodeinfo.ip).arg(nodeinfo.port));
        emit setRole(nodeinfo);
        emit connectToRemoteServer(nodeinfo.ip, nodeinfo.port);
    }
    else if (nodeinfo.noderole == NR_MASTER)
    {
        // The node has existing configuration from previous runs. So we just set and launch up immediately.
        // It would be easier to set the master's IP address from configuration, but we could never be suer
        // that the all IPs are fixed and not moving. (Consider dynamic IP addresses from DHCP) So we still rely
        // in Beacon infrastructure to collect connection information.
        log(0, "We are the master of matrixid: " + nodeinfo.matrixid + ", setting up beacon on port " + nodeinfo.port);
        emit setRole(nodeinfo);
        emit setupCoreServer(nodeinfo);
    }
    else
    {
        log(1, "Unknown nodedole: " + nodeinfo.noderole);
    }
#endif
}

void NodeCore::mastertimer_timeout()
{
    if (nodeinfo.noderole!=NR_UNDECIDED) return;
    // At this point we have looked around the local network, but no matrix signature was present
    // Also loading from configuration file, we could override
    nodeinfo.noderole = NR_MASTER;
    settings->setValue(Conf_NodeRole, NR_MASTER);
    settings->setValue(Conf_Port, 33333);
    settings->setValue(Conf_MatixId, 1);
    nodeinfo.matrixid = settings->value(Conf_MatixId).toString();
    nodeinfo.port = settings->value(Conf_Port).toString();
    QStringList localaddr = HlocalAddresses();
    nodeinfo.port = localaddr.at(0);
    settings->setValue(Conf_IP, nodeinfo.port);
    log(0, "No matrix echo on the network. Promoted to be the master of Matrix: " + nodeinfo.matrixid + " on port " + nodeinfo.port);
    emit setRole(nodeinfo);
    emit setupCoreServer(nodeinfo);
}

void NodeCore::matrixEcho(NodeCoreInfo info)
{
 //   log(0, QString("NodeCore::matrixEcho matrixid:%1, nodeid:%2, noderole:%3, ip:%4, port:%5").arg(info.matrixid).arg(info.nodeid).arg(info.noderole).arg(info.ip).arg(info.port));
    if (info.noderole == NR_MASTER)
    {
        // we found a node controlling a matrix matrix
        if (nodeinfo.matrixid == info.matrixid)
        {
            if (info.noderole == NR_MASTER)
            {
                if (nodeinfo.noderole == NR_MASTER)
                {
                    // CONFLICT - handling needed -> should log this issue on both nodes
                    log(0, "Multiple master - configuration error");
                }
                else if (nodeinfo.noderole==NR_UNDECIDED)
                {
                    // save remote address and our role
                    settings->setValue(Conf_IP, info.ip);
                    settings->setValue(Conf_Port, info.port);
                    settings->setValue(Conf_NodeRole, NR_SLAVE);
                    nodeinfo.ip = settings->value(Conf_IP).toString();
                    nodeinfo.port = settings->value(Conf_Port).toString();
                    nodeinfo.noderole = settings->value(Conf_NodeRole).toString();
                    emit connectToRemoteServer(nodeinfo.ip, nodeinfo.port);

                }
                else if (nodeinfo.noderole == NR_SLAVE)
                {
                    // we use this broadcast as an active beacon ping
                    // thus we know that the master is alive
                }
            }
            else if (info.noderole == NR_SLAVE)
            {
                // Connect
                mastertimer->stop();
                beacon->setBeaconEnabled(false);
                emit connectToRemoteServer(nodeinfo.sessionid, nodeinfo.port);
            }
            else if (info.noderole == NR_UNDECIDED)
            {
                // We connect to this one. We still can instruct master to set our matrix id to
                // something different
            }
        }
    }
    else if (info.noderole == NR_SLAVE)
    {
        // we could use this node to query info about master that might be temporary down
        // or busy. This info could be hijacked (like someone installs and presets a node with false
        // information! We will get over this with mutual authentication as well as limiting installattion
        // window. For now we are not doing anything
    }
}

void NodeCore::joinNetwork(NodeCoreInfo info)
{
    settings->setValue(Conf_NodeRole, info.noderole); 
    settings->setValue(Conf_MatixId, info.matrixid);
    settings->setValue(Conf_Port, info.port);
    settings->setValue(Conf_IP, info.ip);
    nodeinfo = info;
  
    // spin up beacon to attract nodes coming up later
}

void NodeCore::connect(QString id, QString ip, int port)
{
    if (!wsocket) return;
    if (wsocket->state() == QAbstractSocket::ConnectedState)
    {
        wsocket->disconnect();
    }
}


