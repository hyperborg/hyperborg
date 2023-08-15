#include "hsmtask.h"

HSMTask::HSMTask(int id, QObject *parent) : HSMBase(id, parent)
{
    _type = HSM_Task;
}

HSMTask::~HSMTask()
{
}

void HSMTask::init()
{
}

void HSMTask::clear()
{
}

bool HSMTask::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject HSMTask::save(bool states)
{
    QJsonObject retobj = HSMBase::save(states);
     return retobj;
}

Port * HSMTask::getPort(bool output, int idx)
{
    if (!out_ports.count())
    {
        return NULL;
    }
    if (idx==-1)
    {
        return out_ports.first();
    }
    else
    {
        // NOT YET IMPLEMENTED

    }
    return NULL;
}