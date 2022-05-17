#include "hentity.h"

void HEntity::setValue(QString key, HyValue value)
{
    if (!_inupdate)
	_reqSeq++;
    _reqValue = value;
    _reqValues.insert(key, value);
    if (!_inupdate)
        emit setValueChangeRequested(_name);
}

void HEntity::startModification()
{
    if (_inupdate)
    {
        // this should not happen -> log error
        // do not expect to have access serialization here, but let's see if this happens in real life
        // assert out for now
		qDebug() << "ASSERT::startModification";
        Q_ASSERT(_inupdate);
    }
    _inupdate = 1;
    _reqSeq++;
}

void HEntity::endModification()
{
    if (_inupdate == 0)
    {
        // startModification was not called prior -> log error
        // assert out for now
		qDebug() << "ASSERT::endModification";
        Q_ASSERT(!_inupdate);
    }
    emit setValueChangeRequested(_name);
    _inupdate = 0;
}

/* --------------------------------- SERIALIZATION / DESERIALIZATION -------------------------- */

// very basic serialization
DataPack *HEntity::serialize()
{
    QStringList lst;
    DataPack *pack = new DataPack();
    if (pack)
    {
	QHashIterator<QString, HyValue> it(_reqValues);
	while(it.hasNext())
	{
	    it.next();
	    QString key = it.key();
	    HyValue val = it.value();
	    pack->attributes.insert(key, val.value);
	    pack->attributes.insert(key+"_unit", (int)val.unit);
	}

	// Always last to overwrite values from badly behaving devices
	pack->setEntityId(_name);
	pack->attributes.insert("$$ID",	_name);
        pack->attributes.insert("$$REQSEQ", _reqSeq);
    }
    return pack;
}

// very basic deserialization (WITHOUT ERROR HANDLING)
void HEntity::deserialize(DataPack *pack)
{
    if (!pack) return;
    int reply = pack->attributes.value("$$REPLY",  0).toInt();
    int reqs  = pack->attributes.value("$$REQSEQ", -1).toInt();
    if (reqs==-1 || reqs!=_reqSeq)
    {
//	Hmmm ... when and Ok comes back but we started to issue new change, we might still want to 
//	display the old accepted version. Or we should display the old-ok version in case the new
//	request is not acceptable by the mesh. For now, disable this and see how it turns out in 
//	real life. 
//
//	reply = ChangeRequestReply::NotAcceptable;
//
    }

	int chgd = 0;
    switch(reply)
    {
	case 0:
	    // The sender did not say anything about the values, log -> error
	    break;
	case ChangeRequestReply::SetValues:
	case ChangeRequestReply::OkWithModifications:
	    {
		_values.clear();
		QHashIterator<QString, QVariant> it(pack->attributes);
		while (it.hasNext())	// remember, it is hash. Faster than map, but arbitrary ordered, so unit can come before value
		{
		    it.next();
		    QString keysrc = it.key();
		    QString key = keysrc;
		    QVariant val = it.value();
		    bool isunit=false;
		    if (keysrc.mid(keysrc.length()-5)=="_unit")
		    {
			isunit = true;
			key = keysrc.mid(0, keysrc.length()-5);
		    }
		    if (!_values.contains(key))
		    {
			_values.insert(key,HyValue());
		    }
		    if (isunit)
		    {
			_values[key].unit=(Units)val.toInt();
		    }
		    else
		    {
			_values[key].value=val;
		    }
		}
	    }
	    chgd++;
	case ChangeRequestReply::Ok:	// All accepted (should check if new req was issued since!!)
	    _values = _reqValues;	// ACL fault: if user sends endModification and then calls setValue
					// then a returning Ok would dispatch the non-aproved value locally
	    chgd ++;
	    break;
	case ChangeRequestReply::NotAcceptable:
					// Not accepted, simply do nothing
	    break;
    }

    // There is no pending value in _reqValues, so we can clear that now
    if (reqs==-1 || reqs!=_reqSeq)
    {
		_reqValues.clear();
    }

	if (chgd)
    {
	//NI emit entityChanged();
    }

}


