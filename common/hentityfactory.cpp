#include "hentityfactory.h"

static HEntityFactory *hef_instance = NULL;

class delHEFactory
{
    public:
    ~delHEFactory()
    {
	if (hef_instance)
	{
	    delete hef_instance;
	    hef_instance = NULL;
	}
    }
};

HEntityFactory::HEntityFactory(QObject *parent) : QObject(parent)
{
}

HEntityFactory::~HEntityFactory()
{
    QList<HEntity *> lst = entities.values();
    for (int i=0;i<lst.count();i++)
    {
	destroy(lst.at(i));
    }
}

//Note: factory does not hand out the ownership of an entity to the requester
//Entitites contain information for proper shutdown requires after the 
//requester is already deleted. 


void HEntityFactory::enroll(HEntity *entity)
{
    qDebug() << "HEntityFactory::enroll is not yet implemented";
    qDebug() << "It would be used for creating a HEntity outside of the factory, but ";
    qDebug() << "registering that into the factory";
    // not yet implemented
}

void HEntityFactory::destroy(HEntity *entity)
{
    if (!entity) return;
    QMutexLocker lock(&mutex);
    // dispatch info about removed element
    entity->disconnect();	// avoid triggeringy entityDestroyed()
    entity->deleteLater();
    QString key = entities.key(entity);
    entities.remove(key);
}

HEntity *HEntityFactory::get(QString id)
{
    QMutexLocker lock(&mutex);
    HEntity *retent = entities.value(id);
	if (!retent)
	{
   		retent = new HEntity(id);
    	if (retent)
    	{
			QObject::connect(retent, SIGNAL(setValueChangeRequested(QString)), this, SLOT(changeRequested(QString)), Qt::QueuedConnection);
 			entities.insert(retent->name(), retent);
    	}
	}
    return retent;
}

void HEntityFactory::changeRequested(QString str)
{
	QMutexLocker lock(&mutex);
	qDebug() << "emit newPackReady " << str;
    emit newPackReady(new DataPack(str));
}

void HEntityFactory::entityDestroyed(QObject *obj)
{
    if (!obj) return;
    // we go this path, since entity destruction outside of factory 
    // could be a sign of misbehaving plugin
    destroy((HEntity*) obj);
}
