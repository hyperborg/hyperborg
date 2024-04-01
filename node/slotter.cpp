#include "slotter.h"

Slotter::Slotter(HFS* _hfs, QObject* parent) :QObject(parent),//: QThread(parent),
mainPage(NULL), last_seed(0), hfs(_hfs), inbound_buffer(NULL), req_buffer(NULL), qw(NULL), qmlengine(NULL)
{
    hfs->subscribe(this, Bootup_NodeRole, "slotter.topicChanged()", "NODEROLE");
    hfs->subscribe(this, HFS_State, "slotter.topicChanged", "HFSSTATE");
    waitcondition = new QWaitCondition();
    slotter_mutex = new QMutex();
    QObject::connect(hfs, SIGNAL(signal_dataChangeRequest(QString, QVariant)), this, SLOT(dataChangeRequest(QString, QVariant)));

    if (hfs->data(Bootup_GUI).toInt())
    {
        launchHUD();
        loadQML();
    }

    QStringList wlst;
    watcher = new QFileSystemWatcher(this);
    watcher->addPath(hfs->data(Config_MainQML).toString());
    bool f = QObject::connect(watcher, SIGNAL(fileChanged(const QString&)), this, SLOT(fileChanged(const QString&)));
}

// The entity with id has reported its value have been changed
Slotter::~Slotter()
{
    delete waitcondition;
    delete slotter_mutex;
}

void Slotter::log(int severity, QString line, QString src)
{
    hfs->log(severity, line, src);
}

void Slotter::launchHUD()
{
#if 0
    qw = new HQuickWidget();
    if (QQmlContext* ctx = qw->rootContext())
    {
        ctx->setContextProperty("enin$$$QMLEngine", qw->engine());
        ctx->setContextProperty("hfsintf", hfs);
        ctx->setContextProperty("hfs", hfs->getPropertyMap());
    }

    if (isYes(hfs->data("Config_FullScreen").toString()))
    {
//        qw->showFullScreen();
    }
    qw->show();
#else
    qw = NULL;
#endif

    //!! Should be closer to HUDFactory and should deploy only for GUI mode
    qmlRegisterType<HUDButton>("HUDButton", 1, 0, "HUDButton");
    qmlRegisterType<HUDButton>("HUDIFC", 1, 0, "HUDIFC");
    qmlRegisterType<HUDCalendar>("HUDCalendar", 1, 0, "HUDCalendar");
    qmlRegisterType<HUDCalendar>("HUDCalendarEntry", 1, 0, "HUDCalendarEntry");
    qmlRegisterType<HUDClock>("HUDClock", 1, 0, "HUDClock");
    qmlRegisterType<HUDElement>("HUDElement", 1, 0, "HUDElement");
    qmlRegisterType<HUDEventList>("HUDEventList", 1, 0, "HUDEventList");
    qmlRegisterType<HUDGarbage>("HUDGarbage", 1, 0, "HUDGarbage");
    qmlRegisterType<HUDGauge>("HUDGauge", 1, 0, "HUDGauge");
    qmlRegisterType<HUDHFSTree>("HUDHFSTree", 1, 0, "HUDHFSTree");
    qmlRegisterType<HUDLibrary>("HUDLibrary", 1, 0, "HUDLibrary");
    qmlRegisterType<HUDNavigator>("HUDNavigator", 1, 0, "HUDNavigator");
    qmlRegisterType<HUDPowerGrid>("HUDPowerGrid", 1, 0, "HUDPowerGrid");
    qmlRegisterType<HUDScreen>("HUDScreen", 1, 0, "HUDScreen");
    qmlRegisterType<HUDShoppingList>("HUDShoppingList", 1, 0, "HUDShoppingList");
    qmlRegisterType<HUDTimeTable>("HUDTimeTable", 1, 0, "HUDTimeTable");
    qmlRegisterType<HUDTodoList>("HUDTodoList", 1, 0, "HUDTodoList");
    qmlRegisterType<HUDWeather>("HUDWeather", 1, 0, "HUDWeather");
}

void Slotter::loadQML()
{
    QString qmlfile = ":/QML/qmltest.qml";
    QString hfs_qml = hfs->data(Config_MainQML).toString();

#if !WASM
    if (!hfs_qml.isEmpty()) qmlfile = hfs_qml;
#endif

#if 0
    if (qw && qw->rootObject())
    {
        if (qw->rootObject())
            qw->rootObject()->deleteLater();
        if (QQmlEngine* engine = qw->engine())
        {
            engine->clearSingletons();
            // engine->clearCache();
            engine->clearComponentCache();
            engine->collectGarbage();
            //! Might want to clear import paths here
            engine->addImportPath("qrc:/qml");
        }
    }

    QString mqml = hfs->data(Config_MainQML).toString();
    if (!mqml.isEmpty())
    {
        QFileInfo fi(mqml);
        mqml = fi.absolutePath();
        if (!mqml.isEmpty())
        {
            mqml += "/qml";
            if (qw && qw->engine())
                qw->engine()->addImportPath(mqml);
        }
    }


    //    qmle->load(QUrl::fromLocalFile(qmlfile));
    qw->setSource(QUrl::fromLocalFile(qmlfile));
    qw->update();
#else
    if (qmlengine)
    {
        //qmlengine->deleteLater();
        qmlengine = NULL;
    }

    qmlengine = new QQmlApplicationEngine(this);

    if (QQmlContext* ctx = qmlengine->rootContext())
    {
        ctx->setContextProperty("enin$$$QMLEngine", qmlengine);
        ctx->setContextProperty("hfsintf", hfs);
        ctx->setContextProperty("hfs", hfs->getPropertyMap());
    }

    qmlengine->load(qmlfile);
    QObject* toplevel = qmlengine->rootObjects().value(0);
    if ((qw = qobject_cast<QQuickWindow*>(toplevel)))
    {
//        qw->showFullScreen();
    }

#endif


    connectHUDtoHFS();

    //    hudwindow->invalidate();
    //    hudwindow->update();

    hfs->dataChangeRequest(this, "", "config.testSetup", 1);
}

void Slotter::run()
{
    forever
    {
        slotter_mutex->lock();
        waitcondition->wait(slotter_mutex, 2000);
        int pp = 1;
        while (pp)
        {
            pp = 0;
            pp += processPackFromUniCore();
        }
        slotter_mutex->unlock();
    }
}

int Slotter::processPackFromUniCore()
{
    DataPack* pack = inbound_buffer->takeFirst();
/*
    if (!pack) return 0;
    int cmd = pack->command();
    if (cmd == CommandNotDefined)
    {
        QString tentid = pack->entityId();
        log(Info, "processPackFromUniCore tentid: " + tentid);
        log(Info, "No entity to deserialize incoming package");
    }
    else
    {
        executeCommand(cmd, pack);
    }
    delete(pack);   // Your story ended here :D
*/
    return 1;
}

void Slotter::init()
{
    log(Info, "Slotter init");
}

void Slotter::activatePlugins()
{
    log(Info, "Slotter activatePlugins");
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
                QObject::connect(iobj, SIGNAL(signal_sendPack(DataPack*)), this, SLOT(datapackFromHyObj(DataPack*)));
                hobs.insert(iface->name(), iobj);
                if (HyObject* ho = qobject_cast<HyObject*>(iobj))
                {
                    log(Info, "SET ID: " + iface->name());
                    ho->setId(iface->name());
                }
            }
        }
        else log(Info, "NO IFACE found");
    }
}

void Slotter::sendPack(DataPack* pack)
{
    if (!pack) return;
    emit newPackReady(pack);
}

void Slotter::datapackFromHyObj(DataPack* pack)
{
    qDebug() << "DataPack from plugin";
    sendPack(pack);
}

void Slotter::executeCommand(int cmd, DataPack* pack)
{
    return;

    switch (cmd)
    {
    case CommandNotDefined:     // should not reach this point
        break;
    case NOP:                   // do nothing
        break;
    case Ping:                  // register ping
        break;
    case RegisterEntity:        //
        break;
    case UnregisterEntity:      //
        break;
    case SystemEvent:           //
        break;
    case HFSDataChangeRequest:
        if (hfs)
        {
            QString path = pack->attributes.value("path").toString();
            QVariant value = pack->attributes.value("value");
            hfs->setData(path, value);
        }
        break;
    case HFSSetData:
        if (hfs)
        {
            QString path = pack->attributes.value("path").toString();
            QVariant value = pack->attributes.value("value");
            hfs->setData(path, value);
        }
        break;
    default:
        break;
    }
}

QObject* Slotter::getObjectByName(QString name)
{
    if (qmlengine)
    {
        if (QObject* root = qmlengine->rootObjects().value(0))
        {
            return root->findChild<QObject*>(name);
        }
    }
    return nullptr;
}

// Small explanatory for the HUD-Slotter path: The main goal here is to make the plugin's developement as
// easy as possible. We shold not expect that all HUD element would use HFS facility or so. One can just
// create a simple QML element that processes value changes, but does not provide any events backwars.
// Instead of requiring for all elements to know anything about HFS, we just simply sidpaty a setHFS()
// call through Qt's meta-object sstem. If element has the appropriate function, it could register HFS and
// use, if not, this call returns false and we let it that way.

// This "lazy" approach has other benefits. Currently HUDElement inherits from QQuickPaintedItem and there
// could be situations, when the QML element would be implemented in different/other way. Since multiple QObject
// inheritance is a bit problematic in Qt, at this moment no element skeleton is defined or orovided. The
// only thing expected is that the object should be a QObject. All the signals and slots would be discovered
// through QMetaObject functionality.

// One more note: the assignment for each element would be from JSon file and could be set by drag-and-drop.
// Currently this is for the POC.

void Slotter::connectHUDtoHFS()
{
    int id = qRegisterMetaType<HFS>("HFS");
    if (!qw) return;

    //     qmle->rootObjects().at(0)->findChild<QObject*>();
    if (QObject* root = qmlengine->rootObjects().value(0))
    {
        QList<QObject*> children = root->findChildren<QObject*>();

        for (int i = 0; i < children.count(); i++)
        {
            if (children.at(i)->metaObject()->indexOfSlot("setHFS(HFS*)") != -1)
            {
                QMetaObject::invokeMethod(children.at(i), "setHFS", Qt::DirectConnection, Q_ARG(HFS*, hfs));
            }
        }
    }
}

void Slotter::dataChangeRequest(QString path, QVariant value)
{
#if 0
    // sending data change down to other nodes
    if (DataPack* pack = new DataPack())
    {
        pack->setCommand(PackCommands::DataChangeRequest);
        pack->attributes.insert("path", path);
        pack->attributes.insert("value", value);
        sendPack(pack);
    }
#endif
}

QVariant Slotter::nodeRoleChanged(QVariant var)
{
    qDebug() << "Slotter::nodeRoleChanged var:" << var;
    return QVariant();
}

void Slotter::fileChanged(const QString& str)
{
    if (str == hfs->data(Config_MainQML))
    {
        log(Info, "mainqml has been changed, so now it is reloaded");
        loadQML();
        watcher->addPath(hfs->data(Config_MainQML).toString());   // QFileSystemWatcher not tracking file if that is modified by delete-save
    }
}

QVariant Slotter::processTask(Job* job)
{
    QVariant retvar;
    if (!job) return retvar;
    return retvar;
}