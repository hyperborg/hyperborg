#include "slotter.h"

Slotter::Slotter(HEntityFactory *h, QObject* parent) : QThread(parent),
mainPage(NULL)
{
	hfact = h;
    waitcondition = new QWaitCondition();
    slotter_mutex = new QMutex();
    hfs = new HFS(this);
    QObject::connect(hfs, SIGNAL(signal_log(int, QString, QString)), this, SLOT(log(int, QString, QString)));

    qmle = new HUDQMLEngine(this);
    QObject::connect(hfs, SIGNAL(signal_log(int, QString, QString)), this, SLOT(log(int, QString, QString)));

    qmle->rootContext()->setContextProperty("$$$QMLEngine", qmle);

    //!! Shoupd be closer to HUDFactory 
    qmlRegisterType<HUDGauge>("HUDGauge", 1, 0, "HUDGauge");
    qmlRegisterType<HUDGauge>("HUDButton", 1, 0, "HUDButton");
    qmlRegisterType<HUDGauge>("HUDScreen", 1, 0, "HUDScreen");

    QString testfile = "../../../node/samples/qmltest.qml"; 

#ifdef PF_LINUX
    testfile = "qmltest.qml";
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
    emit logLine(severity, line, src);
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
    	if (HEntity *entity = hfact->get(tentid))
    	{
			entity->deserialize(pack);
    	}	
		else
		{
			log(0, "No entity to deserialize incoming package");
		}
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

    if (QObject* button1 = getObjectByName("_button"))
    {
        hfs->interested(button1, "test.switch");
        QMetaObject::invokeMethod(button1, "setHFS", Qt::QueuedConnection, Q_ARG(HFS *, hfs));
    }
}

