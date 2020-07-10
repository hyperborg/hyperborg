#include "slotter.h"

Slotter::Slotter(QObject* parent) : QThread(parent)
{
	waitcondition = new QWaitCondition();
	slotter_mutex = new QMutex();
}

Slotter::~Slotter()
{}

void Slotter::init()
{
    log(0, "Slotter init");
    // create some basic entities for the test system
    QStringList ents;
	    // name, id, attribute, attribute def value
    ents << "LAMP_1,LAMP_1,status,0";
    ents << "LAMP_2,LAMP_2,status,0";
    ents << "LAMP_3,LAMP_3,status,0";
    ents << "LAMP_4,LAMP_4,status,0";
    ents << "LAMP_5,LAMP_5,status,0";

    for (int i=0;i<ents.count();i++)
    {
	QStringList lst =ents.at(i).split(",");
	Entity *ent = new Entity(lst.at(0), lst.at(1));
	QHash<QString, QVariant> hattrs;
	hattrs.insert(lst.at(2), lst.at(3));
	ent->changeValues(hattrs);
	registerEntity(ent);
    }
}

Entity* Slotter::getEntity(QString id)
{
    Entity *retent = NULL;
    for (int i=0;i<entities.count() && !retent;i++)
    {
	if (entities.at(i)->id()==id)		//? should lowercase id all time?
	    retent = entities.at(i);
    }
    return retent;
}

void Slotter::log(int severity, QString line)
{
    emit logLine(severity, line);
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

void Slotter::entityChangeRequested(QHash<QString, QVariant> lst)
{
    log(0, "SLOTTER: entityChangeRequested");
    if (Entity *ent = dynamic_cast<Entity *>(sender()))
    {
	if (DataPack *pack = new DataPack())
        {
    	    pack->attributes=lst;
	    pack->_entityid=ent->id();
	    emit newPackReady(pack);
	}
	else log(0, "SLOTTER: datapack cannot be created");
    } else log(0, "SLOTTER: change request not arrived from an Entity");
}

int Slotter::processPackFromUniCore()
{
    DataPack* pack = inbound_buffer->takeFirst();
    if (!pack) return 0;
    QString tentid = pack->entityId();	// target entity id
    if (Entity *ent = getEntity(tentid))
    {
	ent->changeValues(pack->attributes);
	return 1;
    }
    delete(pack);	// Your story ended here :D
    return 0;
}

void Slotter::registerEntity(Entity* entity)
{
    log(0, QString("Register entity %1 with attr count: %2").arg(entity->id()).arg(entity->count()));
    entities.append(entity);
    QObject::connect(entity, SIGNAL(entityChangeRequested(QHash<QString, QVariant>)), this, SLOT(entityChangeRequested(QHash<QString, QVariant>)));
}

void Slotter::unregisterEntity(Entity* entity)
{
    entities.removeAll(entity);
}

