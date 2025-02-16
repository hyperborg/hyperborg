#include "nodecore.h"

NodeCore::NodeCore(int argc, char * argv[],  QObject* parent) : QObject(parent),
unicore(nullptr), coreserver(nullptr), qmlengine(nullptr),
mainapp(nullptr), _argc(argc), _argv(argv)
{
    hfs = HFS::get();    // HFS is the very first thing that should be created!
    log(Info, "===========================================================================");
    log(Info, QString("HYPERBORG NODE STARTUP version: %1   build: %2").arg(HYPERBORG_VERSION).arg(HYPERBORG_BUILD_TIMESTAMP));
    log(Info, QString("  Current directory: ") + QDir::currentPath());
    log(Info, "===========================================================================");
    hfs->loadBootupIni();

    watcher = std::make_unique<QFileSystemWatcher>(this);
    watcher->addPath(hfs->data(Config_MainQML).toString());
    QObject::connect(watcher.get(), &QFileSystemWatcher::fileChanged, this, &NodeCore::fileChanged);
}

NodeCore::~NodeCore()
{
}

void NodeCore::launch()
{
    if (mainapp)
    {
        mainapp->deleteLater();
        mainapp = nullptr;
    }

    int argc = 0;
    if (guiMode())
    {
        log(0, "-- GUI APPLICATION STARTUP --");
        mainapp = new QApplication(_argc, _argv);
    }
    else
    {
        log(0, "-- CONSOLE APPLICATION STARTUP --");
        mainapp = new QCoreApplication(_argc, _argv);
    }

    setParent(mainapp);
    QCoreApplication::setApplicationName("HyperBorg");
    QCoreApplication::setApplicationVersion(HYPERBORG_VERSION);
    QMetaObject::invokeMethod(this, "launchApplication", Qt::QueuedConnection);
}

void NodeCore::launchApplication()
{
    log(Info, "Launch NodeCore with guimode: " + QString::number(guiMode()));
    hfs->get()->connectToSQL();
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
    QObject::connect(watcher.get(), &QFileSystemWatcher::fileChanged, this, &NodeCore::checkNodeBinary);
    QObject::connect(watcher.get(), &QFileSystemWatcher::directoryChanged, this, &NodeCore::checkNodeBinary);
#endif

//    QMetaObject::invokeMethod(hfs, "startServices", Qt::QueuedConnection);
    if (guiMode())
    {
        loadQML();
    }
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

#if !PF_WASM
    // Generate fingerprint from the executed binary file
    if (qApp->arguments().count()) // should be always true
        node_binary_fingerprint = getBinaryFingerPrint(qApp->arguments().at(0));
    log(Info, "Node binary fingerprint is stored");
#endif
    // -- UNICORE --
    log(Info, "Creating unicore");
    unicore = std::make_unique<UniCore>(hfs, this);
    unicore->setCSSidePackBuffer(ind_buffer);
    hfs->addHFSSubscribes();

    // -- CORESERVER --
    log(Info, "Creating coreserver");
    QString servername = "";
#if PF_WASM || PF_ANDROID
    coreserver = std::make_unique<CoreServer>(hfs, servername, QWebSocketServer::NonSecureMode, 33333);
#else
    coreserver = std::make_unique<CoreServer>(hfs, servername, QWebSocketServer::SecureMode, 33333, this);
#endif
    QObject::connect(this, &NodeCore::connectToRemoteServer, coreserver.get(), &CoreServer::connectToRemoteServer);
    QObject::connect(hfs, &HFS::to_HFS_inBound, unicore.get(), &UniCore::HFS_inBound);

// Fixing call for CS
    QString nr = hfs->data(Bootup_NodeRole).toString();
    Job* j = new Job();
    j->variant = nr;
    coreserver->nodeRoleChanged(j);
    delete j;

    // Creating buffers
    log(Info, "Creating buffers");
    ind_buffer = new PackBuffer(unicore->getWaitCondition());     // Coreserver->Unicore buffer
    outd_buffer = new PackBuffer(nullptr);                        // Unicore->Coreserver buffer

    // CoreServer initial buffers
    log(Info, "Set CS initial buffer");
    coreserver.get()->setInboundBuffer(ind_buffer);
    coreserver.get()->setOutbountBuffer(outd_buffer);

    // datapaths between CoreServer<->UniCore
    log(Info, "Building datapaths between CS<->UC");
    unicore->setCSSidePackBuffer(ind_buffer);
    QObject::connect(coreserver.get(), &CoreServer::incomingData, ind_buffer, &PackBuffer::addPack);
    QObject::connect(unicore.get(), &UniCore::newPackReadyForCS, outd_buffer, &PackBuffer::addPack);
    QObject::connect(outd_buffer, &PackBuffer::newData, coreserver.get(), &CoreServer::newData);

    // Initialize all main modules
    log(Info, "Initialize all modules");
    QMetaObject::invokeMethod(unicore.get(), "init");
    QMetaObject::invokeMethod(coreserver.get(), "init");

    // Launch threads, start executing
    log(Info, "Start modules (threaded execution)");

    log(Info, "Starting unicore");
    unicore->start();

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

/* ===============================================================================================================
    CHECKING BINARY AND RESTARTING SECTION
==================================================================================================================*/

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

/* =============================================================================================================== 
    PLUGIN HANDLING SECTION
==================================================================================================================*/

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
    log(Info, tr(" ============= END OF PLUGIN INITIALIZATION ===================="));
}

void NodeCore::activatePlugins()
{
    log(Info, "NodeCore activatePlugins");
    for (int i = 0; i < pluginslots.count(); i++)
    {
        log(Info, " ------------------------ PLUGIN [" + QString::number(i) + "]-----------------");
        PluginSlot* act = pluginslots.at(i);
        if (HyPluginInterface* iface = act->pluginInterface())
        {
            log(Info, "  Name: " + iface->name());
            log(Info, "  Desc: " + iface->description());
            log(Info, "  Ver : " + iface->version());
            log(Info, "  Auth: " + iface->author());

            if (QObject* iobj = iface->getObject())
            {
                if (HDevice* hd = qobject_cast<HDevice*>(iobj))
                {
                    log(Info, "SET ID: " + iface->name());
                    // ho->setId(iface->name()); //NI??
                }
            }
        }
        else
        {
            log(Info, "NO IFACE found");
        }
    }
}

void NodeCore::connectHUDtoHFS()
{
    qRegisterMetaType<HFS>("HFS");

    if (QObject* root = qmlengine->rootObjects().value(0))
    {
        QList<QObject*> children = root->findChildren<QObject*>();

        for (QObject* child : children)
        {
            if (child->metaObject()->indexOfSlot("setHFS(HFS*)") != -1)
            {
                QMetaObject::invokeMethod(child, "setHFS", Qt::DirectConnection, Q_ARG(HFS*, hfs));
            }
        }
    }
}


/* ===============================================================================================================
    QML HANDLING SECTION
==================================================================================================================*/

void NodeCore::loadQML()
{
    // qmlRegisterType<HUDButton>("HUDButton", 1, 0, "HUDButton");

    QString qmlfile = ":/QML/qmltest.qml";
    QString hfs_qml = hfs->data(Config_MainQML).toString();

#if !PF_WASM
    if (!hfs_qml.isEmpty()) qmlfile = hfs_qml;
#endif

    if (qmlengine.get())
    {
        qmlengine = nullptr;
    }
    qmlengine = std::make_unique<QQmlApplicationEngine>(this);
    qmlengine.get()->addImportPath("c:\\hyperborg");
#if PF_WASM
    qmlengine->addImportPath("qrc:/QML/");
#endif
    if (QQmlContext* ctx = qmlengine.get()->rootContext())
    {
        ctx->setContextProperty("$$$QMLEngine", qmlengine.get());
        ctx->setContextProperty("hfsintf", hfs);
        ctx->setContextProperty("hfs", hfs->getPropertyMap());
        ctx->setContextProperty("HBLook", &HB_LookAndFeel::get());
    }
    qmlengine.get()->load(qmlfile);
    QObject* toplevel = qmlengine.get()->rootObjects().value(0);

    connectHUDtoHFS();
    hfs->dataChangeRequest(this, "", "config.testSetup", 1);
}

void NodeCore::fileChanged(const QString& str)
{
    if (str == hfs->data(Config_MainQML).toString())
    {
        log(Info, "mainqml has been changed, so now it is reloaded");
        loadQML();
        watcher->addPath(hfs->data(Config_MainQML).toString());   // QFileSystemWatcher not tracking file if that is modified by delete-save
    }
}

