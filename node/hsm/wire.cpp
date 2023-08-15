#include "wire.h"

Wire::Wire(int id, QObject *parent) : HSMBase(id, parent)
{
    _type = HSM_Wire;
}

Wire::~Wire()
{
}

void Wire::clear()
{}

bool Wire::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject Wire::save(bool states)
{
    QJsonObject retobj = HSMBase::save(states);
    return retobj;
}

void Wire::createTest()
{}