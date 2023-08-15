#include "hsmjob.h"

HSMJob::HSMJob(int id, QObject *parent) : HSMBase(id, parent)
{
    _type = HSM_Job;
}

HSMJob::~HSMJob()
{
}

void HSMJob::clear()
{
}

bool HSMJob::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject HSMJob::save(bool states)
{
    QJsonObject retobj;
    return retobj;
}

void HSMJob::createTest()
{}