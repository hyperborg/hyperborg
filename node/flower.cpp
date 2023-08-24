#include "flower.h"

Flower::Flower(HFS_Interface *_hfs, QObject *parent) : QObject(parent), hfs(_hfs), idcnt(0)
{}

Flower::~Flower()
{}

void Flower::addExecutor(QString _name, Executor* executor)
{
    if (!executor) return;
    executor->setName(_name);
    addExecutor(executor);
}

void Flower::addExecutor(Executor* executor)
{
    if (!executor) return;
    executors.insert(executor->getName(), executor);
    QObject::connect(executor, SIGNAL(finished(Job*)), this, SLOT(taskExecuted(Job*)));
}

void Flower::startJob(Job* job)
{
}

void Flower::startJob(QString topic, QVariant var)
{
    qDebug() << "startJob topic: " << topic << " var: " << var;
    if (Flow* startflow = flows.value(topic, nullptr))
    {
        startJob(startflow, topic, var);
    }
}

Job* Flower::startJob(Flow* flow, QString topic, QVariant var)
{
    qDebug() << "STARTJOB: " << flow << " topic: " << topic << " var: " << var;
    Job* retjob = NULL;
    if (!flow) return retjob;
    retjob = new Job(idcnt++, flow, topic, var);
    jobs.append(retjob);

    if (flow->exclusive)
    {
        if (flow->locked)    // flow is in execution phase, already enqueued, just return
        {
            return retjob;
        }
        else                // good to go with processing the flow
        {
            flow->locked = true;
        }
    }

    taskExecuted(retjob);
    return retjob;
}

void Flower::taskExecuted(Job* job)
{
    qDebug() << "taskExecuted" << job;
    if (!job || !job->flow) return; // should be handled as error
    int flow_length = job->flow->tasks.count();
    int job_step = ++job->step;
    Flow* lookflow = nullptr;
    if (job_step < flow_length)      // we have not yet reached the end of the flow
    {
        qDebug() << "TE-1";
        if (Task* nexttask = job->flow->tasks.at(job_step))
        {
            QString executorname = nexttask->executor().toLower();
            QString topic = nexttask->topic();
            QString methodname = nexttask->method();

            qDebug() << "TE-1.1  exectutor: " << executorname << "  methodname: " << methodname;
            if (executorname.mid(0,4)== "hfs_")
            {
                qDebug() << "TE-2";
                if (executorname=="hfs_setvalue")
                {
                    qDebug() << "TE-3";
                    hfs->dataChangeRequest(this, "", "", "");
                }
                else if (executorname == "hfs_callmethod")
                {
                    qDebug() << "TE-4";
                    hfs->callMethod(nexttask->topic(), nexttask->method());
                }
            }
            else
            {
                if (Executor* executor = executors.value(executorname, nullptr))
                {
                    qDebug() << "enqueue task: " << nexttask->name();
                    QMetaObject::invokeMethod((QObject*)executor, "enqueueJob", Qt::QueuedConnection, Q_ARG(Job*, job), Q_ARG(QString, methodname));
                }
            }
        }
    }
    else                                // flow execution is finished, clear up!
    {
        if (job->flow->exclusive)
        {
           job->flow->locked = false;
           lookflow = job->flow;
        }
        jobs.removeAll(job);
        qDebug() << jobs.count() << " JOBS remaining";
    }

    Job* nextjob = nullptr;
    if (lookflow)
    {
        for (int i = 0; !nextjob && i < jobs.count(); i++)
        {
            if (jobs.at(i)->flow == lookflow)
            {
                nextjob = jobs.at(i);
            }
        }
    }

    if (nextjob)
    {
        taskExecuted(nextjob);
    }
}