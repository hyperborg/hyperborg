#include "flower.h"
#include "hfs.h"

Flower::Flower(HFS* _hfs, QObject* parent) : QObject(parent), hfs(_hfs), idcnt(0)
{
    if (hfs)
    {
        QObject::connect(hfs, SIGNAL(registerFlow(Flow*, QString)), this, SLOT(addFlow(Flow*, QString)));
        QObject::connect(hfs, SIGNAL(startJob(QString, QString, QVariant)), this, SLOT(startJob(QString, QString, QVariant)));
    }
}

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
    qDebug() << "EXECUTOR " << executor->getName() << " is running in thread: " << executor->thread();
}

void Flower::addFlowTriggerEvent(Flow* flow, QString topic)
{
    if (!flow || !hfs) return;
    QString name = flow->getName();
    if (name.isEmpty())
    {
        QDateTime dt = QDateTime::currentDateTime();
        name = dt.toString("yyyyMMddhhmmsszzz") + hfs->getRandomString(6);
        flow->name = name;
    }

    hfs->subscribe(this, topic, "hfs.startJob()", name);
}

void Flower::startJob(QString topic, QVariant var, QString flow_name)
{
    qDebug() << "startJob topic: " << topic << " var: " << var;
    if (Flow* startflow = flows.value(flow_name, nullptr))
    {
        startJob(startflow, topic, var);
    }
}

void Flower::startJob(QString flow_name, QString topic, QVariant var)
{
    if (Flow* flow = flows[flow_name])
    {
        startJob(flow, topic, var);
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
           // flow->locked = true; // NI!!
        }
    }

    taskExecuted(retjob);
    return retjob;
}

void Flower::addFlow(Flow* flow, QString name)
{
    if (!flow) return;
    if (name.isEmpty()) name = flow->getName();
    flows.insert(name, flow);
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
        if (Task* nexttask = job->flow->tasks.at(job_step))
        {
            QString device = nexttask->device();
            QString executor_id = nexttask->executor();
            qDebug() << "\tCURRENT TASK: " << nexttask->name();
            qDebug() << "\t\tdevice: " << nexttask->device();
            qDebug() << "\t\texecutor_id: " << nexttask->executor();

            if (true || executor_id == ".") executor_id = "gui";  // true - no decentralized execution yet

            if (true || device == ".")              // true - no decentralized execution yet // local device, this should be executed here
            {
                if (executor_id == ".")        // executing in main gui
                {
                }
                else
                {
                    if (Executor* executor = executors[executor_id])
                    {
                        QMetaObject::invokeMethod((QObject*)executor,
                            "enqueueJob",
                            Qt::QueuedConnection,
                            Q_ARG(Job*, job));
                    }
                }
            }
            else if (device == "@")         // execute on the master device
            {
            }
            else                           // named device, routing there
            {
            }
/*
            if (executor==".")

            if (executorname == "hfs")
            {

                if (exec_methodname == "setValue")
                {
                    hfs->dataChangeRequest(this, "", "", "");
                }
                else if (exec_methodname == "callMethod")
                {
                    hfs->callMethod(path, func);
                }
                lookflow = job->flow;

            }
            else
            {
                if (Executor* executor = executors.value(executorname, nullptr))
                {
                    qDebug() << "enqueue task: " << nexttask->name();

                    QMetaObject::invokeMethod((QObject*)executor,
                        "enqueueJob",
                        Qt::QueuedConnection,
                        Q_ARG(Job*, job),
                        Q_ARG(QString, exec_methodname));
                }
                else // Flow has an error
                {
                    // - we should archive the job
                    // - clear the job to save memory
                    jobs.removeAll(job);
                }
            }
*/
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
        QMetaObject::invokeMethod(this, "taskExecuted", Qt::QueuedConnection, Q_ARG(Job*, nextjob));
    }
}