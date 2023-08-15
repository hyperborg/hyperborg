#include "subflow.h"

SubFlow::SubFlow(int id, QObject *parent) : HSMBase(id, parent)
{
    _id = id;
    _type = HSM_SubFlow;
}

SubFlow::~SubFlow()
{
}

void SubFlow::clear()
{
}

bool SubFlow::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject SubFlow::save(bool states)
{
    QJsonObject retobj;
    return retobj;
}

void SubFlow::createTest()
{
}