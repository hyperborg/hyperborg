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

HEntityFactory *HEntityFactory::getInstance()
{
    if (hef_instance) return hef_instance;
    hef_instance = new HEntityFactory(qApp);
    static delHEFactory dhf;
    return hef_instance;
}

HEntityFactory::HEntityFactory(QObject *parent) : QObject(parent), id(1), slotter(NULL)
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

void HEntityFactory::setSlotter(QObject *obj)
{
    slotter = obj;
}

//Note: factory does not hand out the ownership of an entity to the requester
//Entitites contain information for proper shutdown requires after the 
//requester is already deleted. 

HEntity *HEntityFactory::create(QString name, QObject *requester)
{
    QMutexLocker lock(&mutex);
    QString sid = QString::number(id++);
    HEntity* ent = new HEntity(requester, name, name, requester);
    if (ent)
    {
	    QObject::connect(ent, SIGNAL(destroyed(QObject *)), this, SLOT(entityDestroyed(QObject *)));
	    if (slotter)
	    {
	        bool f = QObject::connect(ent, SIGNAL(setValueChangeRequested(QString)), slotter, SLOT(valueChangeRequested(QString)), Qt::QueuedConnection);
	    }
	
	    entities.insert(ent->id(), ent);
    	    if (requester && !requesters.contains(requester))
	    {
	        requesters.append(requester);
	        QObject::connect(requester, SIGNAL(destroyed(QObject *)), this, SLOT(requesterDestroyed(QObject *)));
	    }
    }
    return ent;
}

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
    return retent;
}

void HEntityFactory::requesterDestroyed(QObject *obj)
{
    if (!obj) return;
    QMutexLocker lock(&mutex);
    QList<HEntity*> rme;

    QMultiHash<QString, HEntity*>::iterator i = entities.begin();
    while (i != entities.end())  {
        rme.append(i.value());
        ++i;
    }

    for (int j = 0; j < rme.count(); ++j)
    {
        HEntity* entity = rme.at(j);
        entity->disconnect();	// avoid triggeringy entityDestroyed()
        entity->deleteLater();
        QString key = entities.key(entity);
        entities.remove(key);
    }
}

void HEntityFactory::entityDestroyed(QObject *obj)
{
    if (!obj) return;
    // we go this path, since entity destruction outside of factory 
    // could be a sign of misbehaving plugin
    destroy((HEntity*) obj);
}
