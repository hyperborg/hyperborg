#include "nodecore.h"

NodeCore::NodeCore(int appmode, QObject* parent) : QObject(parent),
unicore(nullptr),
coreserver(nullptr),
_parser(nullptr), _guimode(false)
{
    hfs = HFS::get();    // HFS is the very first thing that should be created!
    log(Info, "===========================================================================");
    log(Info, QString("HYPERBORG NODE STARTUP version: %1   build: %2").arg(HYPERBORG_VERSION).arg(HYPERBORG_BUILD_TIMESTAMP));
    log(Info, QString("  Current directory: ") + QDir::currentPath());
    log(Info, "===========================================================================");
    hfs->loadBootupIni();

    _requiredfeatures = Standard;
    _appmode = appmode;
    _requestedMatrixId = 0;             // Matrix id we want to join by default
}

NodeCore::~NodeCore()
{
}

void NodeCore::launch()
{
    // Launch the application based on the mode
    if (_guimode) {
        launchGUI();
    }
    else {
        launchConsole();
    }
}

void NodeCore::loadPlugins()
{
    log(Info, tr(" ============= PLUGIN INITIALIZATION =========================="));
#ifdef PF_WASM
    log(Info, tr("WebAssembly currently not supporting dynamic libraries (it can load modules though)"));
    return;
#endif

    QStringList namefilters;
    QStringList pluginsdir = { ".", QDir::currentPath(), QDir::currentPath() + "/plugins" };

#ifdef _MSC_VER
    namefilters << "*.dll";
#ifdef _DEBUG
    pluginsdir << "x64/Debug" << QDir::currentPath() + "x64/Debug";
#else
    pluginsdir << "x64/Release" << QDir::currentPath() + "x64/Release";
#endif
#else
    pluginsdir << "plugins";
    namefilters << "*.so";
#endif

    pluginsdir.removeDuplicates();
    QStringList scanned;
    QStringList loaded;

    for (const QString& dir : pluginsdir)
    {
        QDir pluginsDir(dir);
        QString abspath = pluginsDir.absolutePath();
        if (!scanned.contains(abspath))
        {
            scanned.append(abspath);
            log(Info, QString("Checking for plugins in directory: %1").arg(abspath));
            const auto entryList = pluginsDir.entryList(namefilters, QDir::Files);
            for (const QString& fileName : entryList)
            {
                QFileInfo fi(fileName);
                QString basename = fi.baseName();
                if (basename.mid(0, 3).toUpper() == "LIB")
                    basename = basename.mid(3);
                bool load = isYes(hfs->data("plugins." + basename + ".enabled").toString());

                if (load)
                {
                    if (!loaded.contains(basename))
                    {
                        auto pluginslot = std::make_unique<PluginSlot>(hfs, this);
                        if (pluginslot->initializePlugin(pluginsDir.absoluteFilePath(fileName)))
                        {
                            log(Info, QString("Initialized plugin: <%1> from directory: <%2>").arg(fileName).arg(abspath));
                            pluginslots.append(pluginslot.release());
                            loaded.append(basename);
                        }
                        else
                        {
                            log(Info, QString("Discarded plugin: %1").arg(fileName));
                        }
                    }
                    else
                    {
                        log(Warning, QString("Plugin load was attempted multiple times! Plugin name: %1").arg(basename));
                    }
                }
                else
                {
                    log(Info, QString(tr("Plugin <%1> is found, but NOT initialized since it is NOT ENABLED in the config")).arg(basename));
                }
            }
        }
    }
    log(Info, "Plugin loading ends");

    // Determine required features based on loaded plugins
    for (const auto& slot : pluginslots)
    {
        _requiredfeatures |= slot->requiredFeatures();
    }
    log(Info, tr(" ============= END OF PLUGIN INITIALIZATION ===================="));
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
    log(Info, "Launch NodeCore with guimode: " + QString::number(_guimode));
    init();
    connectPlugins();
    initPlugins();

#if !defined(PF_WASM)
    // Start binary/config file change watching
    QObject::connect(&checknodebin_timer, &QTimer::timeout, [=]() { checkNodeBinary(); });
    checknodebin_timer.start(60000);
    checknodebin_timer.setSingleShot(false);
    QStringList wlist = { QDir::currentPath() };
    log(Info, tr("Tracking directory ") + wlist.at(0) + tr(" for changes"));
    watcher = new QFileSystemWatcher(wlist, this);
    QObject::connect(watcher, &QFileSystemWatcher::fileChanged, this, &NodeCore::checkNodeBinary);
    QObject::connect(watcher, &QFileSystemWatcher::directoryChanged, this, &NodeCore::checkNodeBinary);
#endif

    QMetaObject::invokeMethod(hfs, "startServices", Qt::QueuedConnection);
}

void NodeCore::connectPlugins()
{
    for (int i = 0; i < pluginslots.count(); i++)
    {
        log(Info, "Connect plugin: " + QString::number(i));
        pluginslots.at(i)->connectPlugin();
    }
}

void NodeCore::initPlugins()
{
    for (int i = 0; i < pluginslots.count(); i++)
    {
        log(Info, "Init plugin: " + QString::number(i));
        pluginslots.at(i)->initPlugin();
    }
}

void NodeCore::log(int severity, QString logline, QString source)
{
    hfs->log(severity, logline, "NODECORE");
}

void NodeCore::setCMDParser(QCommandLineParser* parser)
{
    _parser = parser;
    if (!parser) return;

    // This is the main place where we are decising a lot of thing about how to behave
    // What we are deciding here is accessible for all plugins (in read only mode of course)


    if (_parser->isSet("config"))
    {
        QString config = _parser->value("config");
        log(Info, "use different config: " + config);
        if (!config.isEmpty())
        {
            hfs->useConfig(_parser->value(config));
        }
    }
    /*

    if (_parser->isSet("matrix"))
    {
        QString tval = _parser->value("matrix");
        log(Info, "presetting matrix: " + tval);
        hfs->setData(Bootup_MatixId, tval);
    }
    */

    /*
    if (_parser->isSet("role"))
    {
        QString tval = _parser->value("role").toUpper();
        log(Info, "presetting role: " + nodeinfo.noderole);
        if (tval=="MASTER" || tval=="SLAVE")
        {
            hfs->setData("config.role", tval);
        }
    }
    */

    if (_parser->isSet("gui"))
    {
        int val = _parser->value("gui").toInt();
        log(Info, "setting forced GUI mode: " + QString::number(val));
        hfs->setData(Bootup_GUI, val);
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
            log(Info, "Presetting remote master node: " + rh);
            hfs->setData("NodeCore", "remote_host", rh);
            log(Info, "Turn beacon off, using remote host: " + rh);
            if (_parser->isSet("remote_port"))
            {
                QString rp = _parser->value("port");
                log(Info, "Using different port for the connection: " + rp);
                hfs->setData("remote_port", rp);
            }
        }
    */
}

QByteArray NodeCore::getBinaryFingerPrint(QString filename)
{
    QByteArray retarray;
#if !defined(PF_WASM)
    QFile bf(qApp->arguments().at(0));
    if (bf.open(QIODevice::ReadOnly))
    {
        QByteArray farr = bf.readAll();
        retarray = QCryptographicHash::hash(farr, QCryptographicHash::Md5);
        bf.close();
    }
#endif
    return retarray;
}

// Creating HFS, since this would be used all over the node. Could be singleton, but since
// it should exist all the time no need to complicate the code. All 4 layers get direct pointer for HFS.
// Also, HFS loads minimal configuration here and also all log are buffered in

void NodeCore::init()
{
    log(Info, "Initialization starts");

#if !defined(PF_WASM)
    // Generate fingerprint from the executed binary file
    if (qApp->arguments().count()) // should be always true
        node_binary_fingerprint = getBinaryFingerPrint(qApp->arguments().at(0));
    log(Info, "Node binary fingerprint is stored");
#endif
    // -- UNICORE --
    log(Info, "Creating unicore");
    unicore = new UniCore(hfs, this);
    unicore->setCSSidePackBuffer(ind_buffer);
    hfs->addHFSSubscribes();

    // -- CORESERVER --
    log(Info, "Creating coreserver");
    QString servername = "";
#if PF_WASM || PF_ANDROID
    coreserver = new CoreServer(hfs, servername, QWebSocketServer::NonSecureMode, 33333);
#else
    coreserver = new CoreServer(hfs, servername, QWebSocketServer::SecureMode, 33333, this);
#endif
    QObject::connect(this, &NodeCore::connectToRemoteServer, coreserver, &CoreServer::connectToRemoteServer);

    QObject::connect(hfs, &HFS::to_HFS_inBound, unicore, &UniCore::HFS_inBound);

    // -- SLOTTER --
    log(Info, "Creating slotter");
    slotter = new Slotter(hfs, this);

    // Creating buffers
    log(Info, "Creating buffers");
    ind_buffer = new PackBuffer(unicore->getWaitCondition());     // Coreserver->Unicore buffer
    outd_buffer = new PackBuffer(nullptr);                           // Unicore->Coreserver buffer
    inp_buffer = new PackBuffer(slotter->getWaitCondition());     // Unicore->Slotter buffer
    outp_buffer = new PackBuffer(unicore->getWaitCondition());    // Slotter->Unicore buffer

    // CoreServer initial buffers
    log(Info, "Set CS initial buffer");
    coreserver->setInboundBuffer(ind_buffer);
    coreserver->setOutbountBuffer(outd_buffer);

    // datapaths between CoreServer<->UniCore
    log(Info, "Building datapaths between CS<->UC");
    unicore->setCSSidePackBuffer(ind_buffer);
    QObject::connect(coreserver, &CoreServer::incomingData, ind_buffer, &PackBuffer::addPack);
    QObject::connect(unicore, &UniCore::newPackReadyForCS, outd_buffer, &PackBuffer::addPack);
    QObject::connect(outd_buffer, &PackBuffer::newData, coreserver, &CoreServer::newData);

    // datapatsh between UniCore<->Slotter
    log(Info, "Building datapaths between UC<->slotter");
    unicore->setSLSidePackBuffer(outp_buffer);
    slotter->setInboundBuffer(inp_buffer);
    QObject::connect(unicore, &UniCore::newPackReadyForSL, inp_buffer, &PackBuffer::addPack);
    QObject::connect(slotter, &Slotter::newPackReady, outp_buffer, &PackBuffer::addPack);

    // Initialize all main modules
    log(Info, "Initialize all modules");
    QMetaObject::invokeMethod(unicore, "init");
    QMetaObject::invokeMethod(coreserver, "init");
    QMetaObject::invokeMethod(slotter, "init");

    // Launch threads, start executing
    log(Info, "Start modules (threaded execution)");

    log(Info, "Starting unicore");
    unicore->start();

    log(Info, "Starting slotter");
    //NI 
    // slotter->start();

    for (auto& slot : pluginslots)
    {
        slotter->addPluginSlot(slot);
    }
    slotter->activatePlugins();

    // It is important to separate the init file and the configuration file
    // The init file helps the node to connect to the mesh. If this one does not exist
    // it depends on the Beacon system to find something to connect to (or being a master)
    // On the other hand, if it turns out that we are the master, we might want to load the
    // bootup code the further fill up the HFS.

    bool role_set = true;
    if (role_set)
    {
        if (hfs->nodeRole() == NR_MASTER)
        {
            log(Info, "This node set role MASTER");
            log(Info, "Loading configuration for master");
            QJsonObject jobj;
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
    log(Info, "Initialization ends");
}

void NodeCore::setGUIMode(int flag)
{
    hfs->setData(Bootup_GUI, flag);
}

int NodeCore::guiMode()
{
    return hfs->data(Bootup_GUI).toInt();
}

/* checkNodeBinary && restartnode

    The following functions are a bit drastic, since they are not shutting
    down the node properly, yet. The main reason for the existence for these
    function at this moment is to support the building and testing of the nodes.

*/
void NodeCore::checkNodeBinary(const QString& str)
{
    if (!qApp->arguments().count()) return;
    QByteArray cb = getBinaryFingerPrint(qApp->arguments().at(0));
    if (cb != node_binary_fingerprint && !cb.isEmpty())
    {
        log(Info, "Node binary has been changed. Restarting in 15 secs.");
        QTimer::singleShot(15 * 1000, this, &NodeCore::restartNode);
    }
}

void NodeCore::restartNode()
{
    // clean up connection and release resources
    log(Info, "RESTART");
    qApp->exit(NODE_RESTART_CODE);
}



