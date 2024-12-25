#include "slotter.h"

Slotter::Slotter(HFS* _hfs, QObject* parent)
    : QObject(parent), mainPage(nullptr), last_seed(0), hfs(_hfs), inbound_buffer(nullptr), req_buffer(nullptr), qw(nullptr), qmlengine(nullptr)
{
    waitcondition = std::make_unique<QWaitCondition>();
    slotter_mutex = std::make_unique<QMutex>();

    if (hfs->data(Bootup_GUI).toInt())
    {
        loadQML();
    }

    watcher = std::make_unique<QFileSystemWatcher>(this);
    watcher->addPath(hfs->data(Config_MainQML).toString());
    QObject::connect(watcher.get(), &QFileSystemWatcher::fileChanged, this, &Slotter::fileChanged);
}

Slotter::~Slotter()
{
    // Smart pointers automatically clean up resources
}

void Slotter::log(int severity, const QString& line, const QString& src)
{
    hfs->log(severity, line, src);
}

void Slotter::loadQML()
{
    // qmlRegisterType<HUDButton>("HUDButton", 1, 0, "HUDButton");


    QString qmlfile = ":/QML/qmltest.qml";
    QString hfs_qml = hfs->data(Config_MainQML).toString();

#if !PF_WASM
    if (!hfs_qml.isEmpty()) qmlfile = hfs_qml;
#endif

    if (qmlengine)
    {
        qmlengine = nullptr;
    }
    qmlengine = std::make_unique<QQmlApplicationEngine>(this);
    if (QQmlContext* ctx = qmlengine->rootContext())
    {
        ctx->setContextProperty("enin$$$QMLEngine", qmlengine.get());
        ctx->setContextProperty("hfsintf", hfs);
        ctx->setContextProperty("hfs", hfs->getPropertyMap());
        ctx->setContextProperty("HBLook", &HB_LookAndFeel::get());
    }
    qmlengine->load(qmlfile);
    QObject* toplevel = qmlengine->rootObjects().value(0);
    int zz = 0;

    connectHUDtoHFS();

    //    hudwindow->invalidate();
    //    hudwindow->update();

    hfs->dataChangeRequest(this, "", "config.testSetup", 1);
}

void Slotter::run()
{
    forever
    {
        QMutexLocker locker(slotter_mutex.get());
        waitcondition->wait(slotter_mutex.get(), 2000);
        while (processPackFromUniCore());
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
        delete pack; // Your story ended here :D
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
                    hobs.insert(iface->name(), iobj);
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

    QObject* Slotter::getObjectByName(const QString& name)
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
        qRegisterMetaType<HFS>("HFS");
        if (!qw) return;

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

    void Slotter::fileChanged(const QString& str)
    {
        if (str == hfs->data(Config_MainQML).toString())
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
