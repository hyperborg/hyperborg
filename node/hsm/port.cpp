#include "port.h"

Port::Port(int id, QObject *parent) : HSMBase(id, parent)
{
    _id = id;
    _type = HSM_Port;
}

Port::~Port()
{}

void Port::clear()
{
}

bool Port::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject Port::save(bool states)
{
    QJsonObject retobj;
    return retobj;
}

void Port::process(JobTracker *jt)
{
    if (jt->pack)
    {
        jt->pack->attributes.insert("port", property("src_label").toString());
    }
    HSMBase::process(jt);
}

