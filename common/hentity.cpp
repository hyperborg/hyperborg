#include "hentity.h"

void HEntity::setValue(QVariant value, QVariant unit)
{
    _value_req = value;
    _unit_req = unit;
    if (!_inupdate)
        emit setValueChangeRequested(_id);
}

void HEntity::setValueAccepted(QVariant value, QVariant unit, QString issue)
{
    qDebug() << "VALUE ACCEPTED: " << _name << " " << value.toString() << " " << unit.toString();
    _value = value;
    _unit = unit;
    emit valueChanged(_value, _unit);
}

// very basic serialization
DataPack *HEntity::serialize()
{
    QStringList lst;
    DataPack *pack = new DataPack();
    if (pack)
    {
	    pack->setEntityId(_name);
	    pack->attributes.insert("$$NAME", 	_name);
	    pack->attributes.insert("$$VALUE_REQ", 	_value_req);
	    pack->attributes.insert("$$UNIT_REQ", 	_unit_req);
	    pack->attributes.insert("$$VALUE", 	_value);
	    pack->attributes.insert("$$UNIT", 	_unit);
	    pack->attributes.insert("$$ID",		_id);
    }
    return pack;
}

// very basic deserialization (WITHOUT ERROR HANDLING)
void HEntity::deserialize(DataPack *pack)
{
    if (!pack) return;
    _value_req = "";
    _unit_req  = "";
    setValueAccepted(pack->attributes.value("$$VALUE", ""), pack->attributes.value("$$UNIT",""), "");
}

void HEntity::startModification()
{
    if (_inupdate)
    {
        // this should not happen -> log error
        // do not expect to have access serialization here, but let's see if this happens in real life
        // assert out for now
        Q_ASSERT(_inupdate);
    }
    _inupdate = 1;
}

void HEntity::endModification()
{
    if (_inupdate == 0)
    {
        // startModification was not called prior -> log error
        // assert out for now
        Q_ASSERT(!_inupdate);
    }
    emit setValueChangeRequested(_id);
    _inupdate = 0;
}



