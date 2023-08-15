#include "hsmflow.h"

HSMFlow::HSMFlow(int id, QObject *parent) : HSMBase(id, parent)
{
    _type = HSM_Flow;
    createTest();
}

HSMFlow::~HSMFlow()
{
}

void HSMFlow::clear()
{
}

bool HSMFlow::load(QJsonObject obj)
{
    HSMBase::load(obj);
    return true;
}

QJsonObject HSMFlow::save(bool states)
{
    QJsonObject retobj = HSMBase::save(states);
    QJsonArray taskarr;
    for (HSMTask *task : tasks)
    {
        taskarr.append(task->save(states));
    }
    retobj["tasks"] = taskarr;

   QJsonArray wirearr;
    for (Wire *wire : wires)
    {
        wirearr.append(wire->save(states));
    }
    retobj["wires"] = taskarr;

    return retobj;
}

void HSMFlow::createTest()
{
    int i;
    Task_Bypass *first_task = NULL;
    Task_Bypass *task=NULL;
    Wire *wire=NULL;
    for (i=0;i<10000;i++)
    {
        task = new Task_Bypass(i, this);
        if (!first_task) first_task = task;
        if (wire) wire->setReceiver(task);
        wire = new Wire(i, this);
        task->getPort()->setReceiver(wire);
    }

    task = new Task_Bypass(i, this);
    if (wire) wire->setReceiver(task);


    first_task->enqueue(new JobTracker());
}
