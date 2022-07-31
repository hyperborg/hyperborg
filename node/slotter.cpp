#include "slotter.h"

Slotter::Slotter(HFS *_hfs,  QObject* parent) : QThread(parent),
mainPage(NULL), last_seed(0), hfs(_hfs)
{
    hfs->interested(this, Conf_NodeRole);
    waitcondition = new QWaitCondition();
    slotter_mutex = new QMutex();
    QObject::connect(hfs, SIGNAL(signal_dataChangeRequest(QString, QVariant, int)), this, SLOT(dataChangeRequest(QString, QVariant, int)));
    qmle = new HUDQMLEngine(this);

    qmle->rootContext()->setContextProperty("$$$QMLEngine", qmle);

    //!! Shoupd be closer to HUDFactory and should deploy only for GUI mode
    qmlRegisterType<HUDGauge>("HUDGauge", 1, 0, "HUDGauge");
    qmlRegisterType<HUDButton>("HUDButton", 1, 0, "HUDButton");
    qmlRegisterType<HUDScreen>("HUDScreen", 1, 0, "HUDScreen");

    QString testfile = ":/QML/qmltest.qml";

#if defined(PF_LINUX)
    testfile = "qmltest.qml";
#else if (defined) PF_EMSCRIP
    testfile = ":/QML/qmltest.qml";
#endif

#if 0
    QQmlComponent component(qmle, QUrl(testfile));
    mainPage = component.create();
#else
    qmle->load(testfile);
#endif
    connectHUDtoHFS();
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
    if (!pack) return 0;
	int cmd = pack->command();
	if (cmd==-1)
	{
 	 	QString tentid = pack->entityId();
		log(0, "processPackFromUniCore tentid: "+tentid);
	    log(0, "No entity to deserialize incoming package");
	}
	else
	{
		executeCommand(cmd, pack);
	}
    delete(pack);	// Your story ended here :D
    return 1;
}

void Slotter::init()
{
    log(0, "Slotter init");
}

void Slotter::activatePlugins()
{
    log(0, "Slotter activatePlugins");
    for (int i=0;i<pluginslots.count();i++)
    {
        log(0, " ------------------------ PLUGIN ["+QString::number(i)+"]-----------------");
        PluginSlot *act = pluginslots.at(i);
        if (HyPluginInterface *iface = act->pluginInterface())
        {
            log(0, "  Name: " + iface->name());
            log(0, "  Desc: " + iface->description());
            log(0, "  Ver : " + iface->version());
            log(0, "  Auth: " + iface->author());
            iface->dumpConfigurationToFile();

			if (QObject *iobj = iface->getObject())
			{
				QObject::connect(iobj, SIGNAL(signal_sendPack(DataPack *)), this, SLOT(datapackFromHyObj(DataPack *)));
				hobs.insert(iface->name(), iobj);
				if (HyObject *ho = qobject_cast<HyObject *>(iobj))
				{
					log(0, "SET ID: "+iface->name());
					ho->setId(iface->name());
				}
			}
        }
        else log(0, "NO IFACE found");
    }
}

void Slotter::loadConfiguration(QJsonObject& obj)
{
    for (int i = 0; i < pluginslots.count(); i++)
    {
        PluginSlot* act = pluginslots.at(i);
        if (HyPluginInterface* iface = act->pluginInterface())
        {
            QJsonValue val = obj[iface->name()];
            if (val.isObject())
            {
                QJsonObject loadobject = val.toObject();
				QMetaObject::invokeMethod(iface->getObject(), "loadConfiguration", Qt::QueuedConnection, Q_ARG(QJsonObject, loadobject));
            }
	    	else qDebug() << "No configuration found for: " << iface->name();
        }
    }
}

void Slotter::saveConfiguration(QJsonObject& obj)
{
    for (int i = 0; i < pluginslots.count(); i++)
    {
        PluginSlot* act = pluginslots.at(i);
        if (HyPluginInterface* iface = act->pluginInterface())
        {
            QJsonObject pobj;
            iface->saveConfiguration(pobj);
            obj[iface->name()] = pobj;
        }
    }
}

void Slotter::sendPack(DataPack *pack)
{
    if (!pack) return;
    emit newPackReady(pack);
}

void Slotter::datapackFromHyObj(DataPack *pack)
{
	qDebug() << "DataPack from plugin";
	sendPack(pack);
}


void Slotter::executeCommand(int cmd, DataPack *pack)
{
	switch(cmd)
	{
		case CommandNotDefined:		// should not reach this point
			break;
		case NOP:					// do nothing
			break;
		case Ping:					// register ping
			break;
		case RegisterEntity:		//
			break;
		case UnregisterEntity:		//
			break;
		case SystemEvent:			//
			break;
        case DataChangeRequest:
            if (hfs)
            {
                QString path = pack->attributes.value("path").toString();
                QVariant value = pack->attributes.value("value");
                int col = pack->attributes.value("column").toInt();
                hfs->setData(path, value, col);
            }
            break;
		default:
			break;
	}
}

QObject* Slotter::getObjectByName(QString name)
{
    if (!mainPage) return NULL;
    return mainPage->findChild<QObject*>(name);
}

// Small explanatorx for the HUD-Slotter path: The main goal here is to make the plugin's developement as
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

    if (QObject* gauge1 = getObjectByName("_gauge"))
    {
        hfs->interested(gauge1, "test.heartbeat");
        QMetaObject::invokeMethod(gauge1, "setHFS", Qt::QueuedConnection, Q_ARG(HFS *, hfs));
    }

    if (QObject* button1 = getObjectByName("_button1"))
    {
        hfs->interested(button1, "test.switch");
        QMetaObject::invokeMethod(button1, "setHFS", Qt::QueuedConnection, Q_ARG(HFS *, hfs));
    }

    if (QObject* button2 = getObjectByName("_button2"))
    {
        hfs->interested(button2, "test.switch");
        QMetaObject::invokeMethod(button2, "setHFS", Qt::QueuedConnection, Q_ARG(HFS*, hfs));
    }

    if (QObject* button3 = getObjectByName("_button3"))
    {
        hfs->interested(button3, "test.switch");
        QMetaObject::invokeMethod(button3, "setHFS", Qt::QueuedConnection, Q_ARG(HFS*, hfs));
    }

}

void Slotter::dataChangeRequest(QString path, QVariant value, int column)
{
    // direct setting the local HFS

    value = last_seed++ % 4;
    hfs->setData(path, value, column);

    // sending data change down to other nodes
    if (DataPack* pack = new DataPack())
    {
        pack->setCommand(DataChangeRequest);
        pack->attributes.insert("path", path);
        pack->attributes.insert("value", value);
        pack->attributes.insert("column", column);
    }
    else
    {
        log(0, "Cannot created datapack in dataChangeRequest");
    }
}

void Slotter::setElementProperty(QString path, QVariant var)
{
    qDebug() << "Slotter::setElementProperty " << path << " " << var;
}

