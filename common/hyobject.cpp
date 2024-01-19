#include "hyobject.h"

/*
void HyObject::registerEntity(QString id)
{
	sendSystemCommand(PackCommands::RegisterEntity, id);
}

void HyObject::unregisterEntity(QString id)
{
	sendSystemCommand(PackCommands::UnregisterEntity, id);
}
*/

// if this is modified, ::setValue should be calling this instead of duplicating insert!
void HyObject::startModification(QString entity_id)
{
	if (entity_id.isEmpty()) entity_id = _id;
	if (!packs.contains(entity_id))
	{
		DataPack* pack = new DataPack();
		packs.insert(entity_id, pack);
	}
}

void HyObject::setValue(QString key, HyValue value, QString entity_id)
{
	bool solo = false;
	DataPack* pack = NULL;
	if (!packs.contains(entity_id))
	{
		solo = true;
		pack = new DataPack();
		packs.insert(entity_id, pack);
	}
	else
	{
		pack = packs.value(entity_id);
	}

	pack->attributes.insert(key, value.value);		// Should use the complete HyValue here!

	if (solo)
	{
		endModification(entity_id);
	}
}

void HyObject::endModification(QString entity_id)
{
	if (entity_id.isEmpty()) entity_id = _id;
	if (packs.contains(entity_id))
	{
		if (DataPack* pack = packs.take(entity_id))
		{
			sendPack(pack);
		}
	}
}

void HyObject::receivePack(DataPack* p)
{
	Q_UNUSED(p);
}

QStringList HyObject::deviceKeys(QString str)
{
    QStringList retlst;
    if (!hfs)	
    {
		qDebug() << "Hyobject has no HFS set!";
		return retlst;
    }
    QStringList lst = hfs->getSubList(str);
    for (int i=0;i<lst.count();++i)
    {
		if (lst.at(i).mid(0,7).toUpper()=="DEVICE_")
		{
			retlst.append(lst.at(i));
		}
    }
    return retlst;
}
