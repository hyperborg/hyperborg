#include "slotter.h"

Slotter::Slotter(HEntityFactory *h, QObject* parent) : QThread(parent),
mainPage(NULL)
{
	hfact = h;
    waitcondition = new QWaitCondition();
    slotter_mutex = new QMutex();
    hfs = new HFS(this);
    QObject::connect(hfs, SIGNAL(signal_log(int, QString)), this, SLOT(log(int, QString)));

    qmle = new HUDQMLEngine(this);
    qmle->rootContext()->setContextProperty("$$$QMLEngine", qmle);

    qmlRegisterType<HUDGauge>("Gauge", 1, 0, "Gauge");

    QString testfile = "../../../node/samples/qmltest.qml";

#ifdef PF_LINUX
    testfile = "qmltest.qml";
#endif
    QQmlComponent component(qmle, QUrl(testfile));
    mainPage = component.create();
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

void Slotter::connectHUDtoHFS()
{
    if (QObject* gauge1 = getObjectByName("_gauge"))
    {
        hfs->interested(gauge1, "test.heartbeat");
    }

}

