#include "nodecore.h"

NodeCore::NodeCore(int argc, char * argv[],  QObject* parent) : QObject(parent),
_argc(argc), _argv(argv), prevstate_str("state"), unicore(nullptr), coreserver(nullptr), qmlengine(nullptr), mainapp(nullptr)
{ 
    elapsed.start();
    hfs = HFS::get();    // HFS is the very first thing that should be created!
    log(Info, "===========================================================================");
    log(Info, QString("HYPERBORG NODE STARTUP version: %1   build: %2").arg(HYPERBORG_VERSION).arg(HYPERBORG_BUILD_TIMESTAMP));
    log(Info, QString("  Current directory: ") + QDir::currentPath());
    log(Info, "===========================================================================");

    // HFS should be loaded and application created before any event loop can be executed (like state machine)
    hfs->loadBootupIni();
    createApp();

    createStateMachine();
}

NodeCore::~NodeCore()
{
}

void NodeCore::createApp()
{
    if (mainapp)
    {
        mainapp->deleteLater();
        mainapp = nullptr;
    }

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
//    QMetaObject::invokeMethod(this, "launchApplication", Qt::QueuedConnection);
}

void NodeCore::createStateMachine()
{
    statemachine.reset(new QStateMachine());
    state_start.reset(new QState());                    state_start.get()->setObjectName("state_start");
    state_init.reset(new QState());                     state_init.get()->setObjectName("state_init");
    state_launch.reset(new QState());                   state_launch.get()->setObjectName("state_launch");
    state_qml.reset(new QState());                      state_qml.get()->setObjectName("state_qml");
    state_split.reset(new QState());                    state_split.get()->setObjectName("state_split");
    state_sync.reset(new QState());                     state_sync.get()->setObjectName("state_sync");
    state_plugins.reset(new QState());                  state_plugins.get()->setObjectName("state_plugins");
    state_online.reset(new QState());                   state_online.get()->setObjectName("state_online");
    state_standby.reset(new QState());                  state_standby.get()->setObjectName("state_standby");
    state_fork.reset(new QState());                     state_fork.get()->setObjectName("state_fork");

    statemachine.get()->addState(state_start.get());    state_start.get()->assignProperty(this,   prevstate_str.toLatin1().data(), state_start->objectName());
    statemachine.get()->addState(state_init.get());     state_init.get()->assignProperty(this,    prevstate_str.toLatin1().data(), state_init->objectName());
    statemachine.get()->addState(state_launch.get());   state_launch.get()->assignProperty(this,  prevstate_str.toLatin1().data(), state_launch->objectName());
    statemachine.get()->addState(state_qml.get());      state_qml.get()->assignProperty(this,     prevstate_str.toLatin1().data(), state_qml->objectName());
    statemachine.get()->addState(state_split.get());    state_split.get()->assignProperty(this,   prevstate_str.toLatin1().data(), state_split->objectName());
    statemachine.get()->addState(state_sync.get());     state_sync.get()->assignProperty(this,    prevstate_str.toLatin1().data(), state_sync->objectName());
    statemachine.get()->addState(state_plugins.get());  state_plugins.get()->assignProperty(this, prevstate_str.toLatin1().data(), state_plugins->objectName());
    statemachine.get()->addState(state_online.get());   state_online.get()->assignProperty(this,  prevstate_str.toLatin1().data(), state_online->objectName());
    statemachine.get()->addState(state_standby.get());  state_standby.get()->assignProperty(this, prevstate_str.toLatin1().data(), state_standby->objectName());
    statemachine.get()->addState(state_fork.get());     state_fork.get()->assignProperty(this,    prevstate_str.toLatin1().data(), state_fork->objectName());

    QObject::connect(state_start.get(),   &QState::entered, this, &NodeCore::stateStartEntered);
    QObject::connect(state_start.get(),   &QState::exited,  this, &NodeCore::stateStartExited);
    QObject::connect(state_init.get(),    &QState::entered, this, &NodeCore::stateInitEntered);
    QObject::connect(state_init.get(),    &QState::exited,  this, &NodeCore::stateInitExited);
    QObject::connect(state_launch.get(),  &QState::entered, this, &NodeCore::stateLaunchEntered);
    QObject::connect(state_launch.get(),  &QState::exited,  this, &NodeCore::stateLaunchExited);
    QObject::connect(state_qml.get(),     &QState::entered, this, &NodeCore::stateQMLEntered);
    QObject::connect(state_qml.get(),     &QState::exited,  this, &NodeCore::stateQMLExited);
    QObject::connect(state_split.get(),   &QState::entered, this, &NodeCore::stateSplitEntered);
    QObject::connect(state_split.get(),   &QState::exited,  this, &NodeCore::stateSplitExited);
    QObject::connect(state_sync.get(),    &QState::entered, this, &NodeCore::stateSyncEntered);
    QObject::connect(state_sync.get(),    &QState::exited,  this, &NodeCore::stateSyncExited);
    QObject::connect(state_plugins.get(), &QState::entered, this, &NodeCore::statePluginsEntered);
    QObject::connect(state_plugins.get(), &QState::exited,  this, &NodeCore::statePluginsExited);
    QObject::connect(state_online.get(),  &QState::entered, this, &NodeCore::stateOnlineEntered);
    QObject::connect(state_online.get(),  &QState::exited,  this, &NodeCore::stateOnlineExited);
    QObject::connect(state_standby.get(), &QState::entered, this, &NodeCore::stateStandByEntered);
    QObject::connect(state_standby.get(), &QState::exited,  this, &NodeCore::stateStandByExited);
    QObject::connect(state_fork.get(),    &QState::entered, this, &NodeCore::stateForkEntered);
    QObject::connect(state_fork.get(),    &QState::exited,  this, &NodeCore::stateForkExited);

    // Adding transitions
    state_start.get()->addTransition(this, &NodeCore::startFinished, state_init.get());
    state_init.get()->addTransition(this, &NodeCore::initFinished, state_launch.get());
    state_launch.get()->addTransition(this, &NodeCore::launchFinished, state_qml.get());
    state_qml.get()->addTransition(this, &NodeCore::qmlFinished, state_split.get());
    state_split.get()->addTransition(this, &NodeCore::splitFinished, state_sync.get());
    state_sync.get()->addTransition(this, &NodeCore::syncFinished, state_plugins.get());
    state_plugins.get()->addTransition(this, &NodeCore::pluginsFinished, state_online.get());

    statemachine.get()->setInitialState(state_start.get());
    statemachine.get()->setProperty("previousState", QVariant());
    statemachine.get()->start();
}

void NodeCore::stateStartEntered()
{
    emit startFinished();
}

void NodeCore::stateStartExited()
{
}

/* ============================================== STATE INIT =====================================================*/

void NodeCore::stateInitEntered()
{
    log(Info, "INIT state entered");
    hfs->loadBootupIni();

    // Reset unicore 
    if (unicore) unicore.get()->terminate();
    unicore.reset(new UniCore(hfs, this));
    hfs->addHFSSubscribes();

    // Reset coreserver
    coreserver.reset(new CoreServer(hfs, "", QWebSocketServer::SecureMode, 33333, this));
    QObject::connect(this, &NodeCore::connectToRemoteServer, coreserver.get(), &CoreServer::connectToRemoteServer);
    QObject::connect(hfs, &HFS::to_HFS_inBound, unicore.get(), &UniCore::HFS_inBound);

    // Reset internal buffers
    ind_buffer.reset(new PackBuffer(this, unicore->getWaitCondition()));
    outd_buffer.reset(new PackBuffer(this));

    // Creating buffers and connecting their signals
    coreserver.get()->setInboundBuffer(ind_buffer.get());
    coreserver.get()->setOutbountBuffer(outd_buffer.get());
    unicore->setCSSidePackBuffer(ind_buffer.get());
    QObject::connect(coreserver.get(), &CoreServer::incomingData, ind_buffer.get(), &PackBuffer::addPack);
    QObject::connect(unicore.get(), &UniCore::newPackReadyForCS, outd_buffer.get(), &PackBuffer::addPack);
    QObject::connect(outd_buffer.get(), &PackBuffer::newData, coreserver.get(), &CoreServer::newData);

    // Initialize and start main modules (unicore and coreserver)
    QMetaObject::invokeMethod(unicore.get(), "init");
    QMetaObject::invokeMethod(coreserver.get(), "init");
    emit initFinished();
}

void NodeCore::stateInitExited()
{
}

/* ============================================== STATE LAUNCH ===================================================*/

void NodeCore::stateLaunchEntered()
{
    // setup watcher for config file and executable
#if 0  //File change tracking is disabled
#if !PF_WASM || !PF_ANDROID
    watcher.reset(new QFileSystemWatcher(this));
    watcher->addPath(hfs->data(Config_MainQML).toString());
    if (qApp->arguments().count()) // should be always true
    {
        node_binary_fingerprint = getBinaryFingerPrint(qApp->arguments().at(0));
        watcher->addPath(qApp->arguments().at(0));
    }
    QObject::connect(watcher.get(), &QFileSystemWatcher::fileChanged, this, &NodeCore::fileChanged);
    hfs->get()->connectToSQL();
#endif
#endif
    unicore->start();
    emit launchFinished();
}

void NodeCore::stateLaunchExited()
{
}

/* ============================================== STATE QML ======================================================*/

void NodeCore::stateQMLEntered()
{
    qDebug() << "QML-1 " << elapsed.elapsed();
    if (guiMode())
    {
        qDebug() << "QML-2 " << elapsed.elapsed();
        qmlengine.reset(new QQmlApplicationEngine(this));
        qDebug() << "QML-3 " << elapsed.elapsed();

        QString qmlfile = ":/QML/qmltest.qml";
        QString hfs_qml = hfs->data(Config_MainQML).toString();
        qDebug() << "QML-4 " << elapsed.elapsed();

#if !PF_WASM || !PF_ANDROID
        if (!hfs_qml.isEmpty()) qmlfile = hfs_qml;
        qmlengine->addImportPath("qrc:/QML/");
#endif
        qDebug() << "QML-5 " << elapsed.elapsed();

        qmlengine.get()->addImportPath("c:\\hyperborg");
        if (QQmlContext* ctx = qmlengine.get()->rootContext())
        {
            ctx->setContextProperty("$$$QMLEngine", qmlengine.get());
            ctx->setContextProperty("hfscall", hfs);
            ctx->setContextProperty("hfs", hfs->getPropertyMap());
            ctx->setContextProperty("HBLook", &HB_LookAndFeel::get());
        }
        qDebug() << "QML-6 " << elapsed.elapsed();
        qmlengine.get()->load(qmlfile);
        qDebug() << "QML-7 " << elapsed.elapsed();
        hfs->dataChangeRequest(this, "", "config.testSetup", 1);
        qDebug() << "QML-8 " << elapsed.elapsed();
    }
    emit qmlFinished();
}

void NodeCore::stateQMLExited()
{
}

/* ============================================== STATE SPLIT ====================================================*/


void NodeCore::stateSplitEntered()
{
    emit splitFinished();
}

void NodeCore::stateSplitExited()
{
}

/* ============================================== STATE SYNC =====================================================*/

void NodeCore::stateSyncEntered()
{
    emit syncFinished();
}

void NodeCore::stateSyncExited()
{
}

/* ============================================== STATE PLUGINS ==================================================*/
// Please note, that this state can be reached after online state reached.
// The implementation of this function should be able to recognise modified plugins and reload them on-the-fly.
void NodeCore::statePluginsEntered()
{
    emit pluginsFinished();
    return;
#if PF_WASM     
    emit pluginsFinished();     // WebAssembly currently does not support plugins 
#endif

    // First we set in which directory we would like to search for plugins

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

    for (const QString& dir : pluginsdir)
    {
        QDir pluginsDir(dir);
        QString abspath = pluginsDir.absolutePath();
        log(Info, QString("Checking for plugins in directory: %1").arg(abspath));
        const auto entryList = pluginsDir.entryList(namefilters, QDir::Files);
        for (const QString& fileName : entryList)
        {
            QFileInfo fi(fileName);
            QString basename = fi.baseName();
            if (basename.mid(0, 3).toUpper() == "LIB")
                basename = basename.mid(3);
            bool enabled = isYes(hfs->data("plugins." + basename + ".enabled").toString());
            bool loaded = pluginslots.contains(basename);

            if (enabled)
            {
                if (!loaded)
                {
                    auto pluginslot = std::make_unique<PluginSlot>(hfs, this);
                    if (pluginslot->load(pluginsDir.absoluteFilePath(fileName)))
                    {
                        log(Info, QString("Initialized plugin: <%1> from directory: <%2>").arg(fileName).arg(abspath));
                        pluginslot.get()->init();
                        pluginslot.get()->connect();

                        log(Info, " ------------------------ PLUGIN [" +basename + "]-----------------");
                        if (HyPluginInterface* iface = pluginslot.get()->pluginInterface())
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
                                }
                            }
                        }
                        log(Info, " -------------------------------------------------------------------");
                        pluginslots.insert(basename, pluginslot.release());
                    }
                    else
                        log(Info, QString("Discarded plugin: %1").arg(fileName));
                }
                else // plugin is already loaded, need to check if configuration is changed
                {
                }
            }
            else // !enabled
            {
                if (loaded) // the plugin is loaded, but not enabled anymore, so we do remove it from the active plugins
                {
                    if (PluginSlot* plugin = pluginslots.take(basename))
                    {
                        plugin->unload();
                        plugin->deleteLater();
                    }
                }
                else
                    log(Info, QString(tr("Plugin <%1> is found, but NOT initialized since it is NOT ENABLED in the config")).arg(basename));
            }
        }
    }

    emit pluginsFinished();
}

void NodeCore::statePluginsExited()
{
}

/* ============================================== STATE ONLINE ===================================================*/


void NodeCore::stateOnlineEntered()
{
    qDebug() << "ONLINE AT: " << elapsed.elapsed() << "ms";
    int zz = 0;
    zz++;
}

void NodeCore::stateOnlineExited()
{
}

/* ============================================== STATE STANDBY ==================================================*/


void NodeCore::stateStandByEntered()
{
    emit standByFinished();

}

void NodeCore::stateStandByExited()
{
}

/* ============================================== STATE FORK =====================================================*/


void NodeCore::stateForkEntered()
{
    emit forkFinished();
}

void NodeCore::stateForkExited()
{
}

/* ===============================================================================================================*/

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

/*
void NodeCore::fileChanged(const QString& str)
{
    if (str == hfs->data(Config_MainQML).toString())
    {
        log(Info, "mainqml has been changed, so now it is reloaded");
        loadQML();
        watcher->addPath(hfs->data(Config_MainQML).toString());   // QFileSystemWatcher not tracking file if that is modified by delete-save
    }
}
*/

QString NodeCore::state()
{
    return _state;
}

void NodeCore::setState(QString str)
{
    _state = str;
    qDebug() << elapsed.elapsed() << "  STATE: " << str;
}
