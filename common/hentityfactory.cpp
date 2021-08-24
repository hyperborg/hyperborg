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
    qDebug() << "HEF instance: " << hef_instance;
    static delHEFactory dhf;
    return hef_instance;
}

HEntityFactory::HEntityFactory(QObject *parent) : QObject(parent), id(1)
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

HEntity *HEntityFactory::create(QString name, QObject *requester)
{
    QMutexLocker lock(&mutex);
    HEntity* ent = new HEntity(requester, name, QString::number(id++), this);
    if (ent)
    {
	QObject::connect(ent, SIGNAL(destroyed(QObject *)), this, SLOT(entityDestroyed(QObject *)));
	entities.insert(name, ent);
        if (!requesters.contains(requester))
	    {
	        requesters.append(requester);
	        QObject::connect(requester, SIGNAL(destroyed(QObject *)), this, SLOT(requesterDestroyed(QObject *)));
	    }
    }
    return ent;
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
