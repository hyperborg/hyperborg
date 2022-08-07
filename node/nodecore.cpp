#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject *parent) : QObject(parent),
unicore(NULL),
coreserver(NULL), coreserver_thread(NULL),
beacon(NULL), beacon_thread(NULL), _parser(NULL), _guimode(false),
 wsocket(NULL), mastertimer(NULL)
{
#if HTEST   // delete log file at each startup to ease debugging
    QFile f(QDir::homePath() + "/hyperborg.log");
    if (!f.remove())
    {
        log(0, "hyperborg.log file cannot be removed!");
    }
#endif

//    int id = qRegisterMetaType<NodeCoreInfo>("NodeCoreInfo");

    log(0, "===========================================================================");
    log(0, QString("HYPERBORG NODE STARTUP version: %1   build: %2").arg(HYPERBORG_VERSION).arg(HYPERBORG_BUILD_TIMESTAMP));
    log(0, QString("  Current directory: ") + QDir::currentPath());
    log(0, "===========================================================================");
    hfs = new HFS(this);    // HFS is the very first thing that should be created!

    _requiredfeatures = Standard;
    _appmode = appmode;
    _requestedMatrixId = 0;	                // Matrix id we want to join by default
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
    log(Info, "Plugin load started");
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
    log(Info, "Plugin loading ends");

    // We loaded what we could load. Now we define whether we run in console or GUI mode (needed for QApplication creation)
    for (int i=0;i<pluginslots.count();++i)
    {
        _requiredfeatures |= pluginslots.at(i)->requiredFeatures();
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
    connectPlugins();
    initPlugins();
    
#if !defined(WASM)
    // starting up binary/config file change watching
    QObject::connect(&checknodebin_timer, SIGNAL(timeout()), this, SLOT(checkNodeBinary()));
    checknodebin_timer.start(60000);
    checknodebin_timer.setSingleShot(false);
    QStringList wlist;
    wlist << QDir::currentPath();
    log(0, tr("Tracking directory ") + wlist.at(0) + tr(" for changes"));
    watcher = new QFileSystemWatcher(wlist, this);
    QObject::connect(watcher, SIGNAL(fileChanged(QString)), this, SLOT(checkNodeBinary(QString)));
    QObject::connect(watcher, SIGNAL(directoryChanged(QString)), this, SLOT(checkNodeBinary(QString)));
#endif
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

void NodeCore::log(int severity, QString logline, QString src)
{
    hfs->log(severity, logline, src);
}

void NodeCore::setCMDParser(QCommandLineParser *parser)
{
    _parser=parser;
    if (!parser) return;

    // This is the main place where we are decising a lot of thing about how to behave
    // What we are deciding here is accessible for all plugins (in read only mode of course)

    /*
    if (_parser->isSet("config"))
    {
        QString config = _parser->value("config");
        log(0, "use different config: " + config);
        if (!config.isEmpty())
        {
            settings->useSettings(_parser->value(config));
        }
    }

    if (_parser->isSet("matrix"))
    {
        QString tval = _parser->value("matrix");
        log(0, "presetting matrix: " + tval);
        hfs->setData(Conf_MatixId, tval);
    }
    */

    /*
    if (_parser->isSet("role"))
    {
        QString tval = _parser->value("role").toUpper();
        log(0, "presetting role: " + nodeinfo.noderole);
        if (tval=="MASTER" || tval=="SLAVE")
        {
            hfs->setData("config.role", tval);
        }
    }
    */

    if (_parser->isSet("gui"))
    {
        int val = _parser->value("gui").toInt();
        log(0, "setting forced GUI mode: " + QString::number(val)); 
        hfs->setData(Conf_GUI, val);
    }
/*
    if (_parser->isSet("f"))
    {
    qDebug() << "Foreground is set";
    hfs->setData("NodeCore", "foreground", "true");
    }

    if (_parser->isSet("no-gui"))
    {
    qDebug() << "disable GUI mode";
    hfs->setData("NodeCore", "disable_gui", "true");
    }

    if (_parser->isSet("remotehost"))
    {
        QString rh = _parser->value("remotehost");
        log(0, "Presetting remote master node: " + rh);
        hfs->setData("NodeCore", "remote_host", rh);
        log(0, "Turn beacon off, using remote host: " + rh);
        if (_parser->isSet("remote_port"))
        {
            QString rp = _parser->value("port");
            log(0, "Using different port for the connection: " + rp);
            hfs->setData("remote_port", rp);
        }
    }
*/
}

QByteArray NodeCore::getBinaryFingerPrint(QString filename)
{
    QByteArray retarray;
#if !defined(WASM)
    QFile bf(qApp->arguments().at(0));
    if (bf.open(QIODevice::ReadOnly))
    {
        QByteArray farr = bf.readAll();
        QByteArrayView bav(farr);
	    retarray = QCryptographicHash::hash(bav, QCryptographicHash::Md5);
	    bf.close();
    }
#endif
    return retarray;
}

void NodeCore::init()
{
    log(0, "Initialization starts");

    // Creating HFS, since this would be used all over the node. Could be singleton, but since 
    // it should exist all the time no need to complicate the code. All 4 layers git direct pointer for HFS.
    // Also, HFS loads minimal configuration here and also all log are buffered in

#if !defined(WASM)
    // Generate fingerprint from the executed binary file
    if (qApp->arguments().count()) // should be always true
	node_binary_fingerprint = getBinaryFingerPrint(qApp->arguments().at(0));
    log(0, "Node binary fingerprint is stored");
#endif

	// Creating hentity factory
	log(0, "Creating hentity factory");

    // Creating main modules
    log(0, "Creating main modules");
    
    // -- BEACON --
    log(0, "Creating beacon");
    beacon = new Beacon(hfs);
    beacon_thread = new QThread();
    beacon->moveToThread(beacon_thread);

    // -- CORESERVER --
    log(0, "Creating coreserver");
    QString servername = "hyperborg-node";
    coreserver = new CoreServer(hfs, servername, QWebSocketServer::NonSecureMode, 33333); 
    coreserver_thread = new QThread();
    QObject::connect(this, SIGNAL(connectToRemoteServer(QString, QString)), coreserver, SLOT(connectToRemoteServer(QString, QString))); 

    // -- UNICORE --
    log(0, "Creating unicore");
    unicore = new UniCore(hfs);
    unicore->setCSSidePackBuffer(ind_buffer);

    // -- SLOTTER --
    log(0, "Creating slotter");
    slotter = new Slotter(hfs);

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
    slotter->setInboundBuffer(inp_buffer);
    QObject::connect(unicore, SIGNAL(newPackReadyForSL(DataPack*)), inp_buffer, SLOT(addPack(DataPack*)));
    QObject::connect(slotter, SIGNAL(newPackReady(DataPack*)), outp_buffer, SLOT(addPack(DataPack*)));

    // Initialize all main modules
    log(0, "Initialize all modules");
    QMetaObject::invokeMethod(unicore, "init");
    QMetaObject::invokeMethod(beacon, "init");
    QMetaObject::invokeMethod(coreserver, "init");
    QMetaObject::invokeMethod(slotter, "init");

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


    // At this point all necesseary elements are loaded into the node and ready to run.
    // By loading the configuration from files it will trigger the correct setups
    bool role_set = hfs->loadInitFiles();

    // It is important to separate the init file and the configuration file
    // The init file helps the node to connect to the mesh. If this one does not exist
    // it depends on the Beacon system to find something to connect to (or being a master)
    // On the other hand, if it turns out that we are the master, we might want to load the
    // bootup code the further fill up the HFS.

    if (role_set)
    {
        if (hfs->data(Conf_NodeRole).toString() == NR_MASTER)
        {
            log(0, "This node set role MATER");
            log(0, "Loading configuration for master");
            QJsonObject jobj;
            loadConfiguration(jobj);
        }
        else    // This node is slave
        {
            // Should connect to the mesh
        }
    }
    else
    {
        // Launch Beacon to find others or make this a master
    }
        log(0, "Initialization ends");
}

// LoadConfiguration stops all layers, clear execution stacks and all modules
// are forced to reload configuration
void NodeCore::loadConfiguration(QJsonObject& json)
{
    log(0, "NodeCore::loadConfiguration should come from HFS from now on");
    return;

    QStringList cfgs;
    cfgs << "/etc/hyperborg/master.imi";
    cfgs << "c:\\hyperborg\\master.imi";
    cfgs << "master.imi";

    QJsonParseError parseError;
    bool parsed = false;

    for (int i = 0; i < cfgs.count() && !parsed; i++)
    {
	qDebug() << "Testing: " << cfgs.at(i);
        QFile cfgf(cfgs.at(i));
        if (cfgf.open(QIODevice::ReadOnly))
        {
            qDebug() << "Using configuration file: " << cfgs.at(i);
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
		qDebug() << "checking for slotter configuration";
                if (json_slotter.isObject())
                {
                    if (slotter)
                    {
                        QJsonObject lobj = json_slotter.toObject();
                        slotter->loadConfiguration(lobj);
                    } else qDebug() <<"!! slotter is NULL";
                } else qDebug() << "!! json_slotter is not object!";

                parsed = true;
            }
            else
            {
                log(0, QString("While opening configuration file [%1] JSON parsing error happened: %2").arg(cfgs.at(i)).arg(parseError.errorString()));
            }
        }
    }
}

void NodeCore::setGUIMode(int flag)
{
    hfs->setData(Conf_GUI, flag);
}

int NodeCore::guiMode()
{
    return hfs->data(Conf_GUI).toInt();
}

void NodeCore::saveConfiguration(QJsonObject& json)
{
    log(0, "NodeCore::saveConfiguration should come from HFS from now on");
    return;

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
        log(0, "Node binary has been changed. Restarting in 15 secs.");
        QTimer::singleShot(15 * 1000, this, SLOT(restartNode()));
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

void NodeCore::connect(QString id, QString ip, int port)
{
    if (!wsocket) return;
    if (wsocket->state() == QAbstractSocket::ConnectedState)
    {
        wsocket->disconnect();
    }
}


