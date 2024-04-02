#include "flower.h"
#include "hfs.h"

Flower::Flower(HFS* _hfs, QObject* parent) : QObject(parent), hfs(_hfs), idcnt(0)
{
    if (hfs)
    {
        hfs->setFlower(this);
        bool f = QObject::connect(hfs, SIGNAL(startJob(QString, QString, QVariant)), this, SLOT(startJob(QString, QString, QVariant)));
        hfs->provides(this, "flower.startJob()", HFS_LocalUsage);
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

    hfs->subscribe(this, topic, "flower.startJob()", name);
}

void Flower::startJob(QString topic, QVariant var, QString flow_name)
{
    qDebug() << "startJob topic: " << topic << " var: " << var;
    if (Flow* startflow = flows.value(flow_name, nullptr))
    {
        startJob(startflow, topic, var);
    }
}

void Flower::jobTransferred(Job* job)
{
    if (!job) return;
    QString flow_name = job->flow_name;
    int nid = job->id;

    Job* ojob = NULL;

    if (ojob = jobs.value(nid, NULL))               // job returned from remote, swap!
    {
        jobs.remove(nid);
        jobs.insert(nid, job);
        ojob->deleteLater();
    }

    if (Flow* flow = flows.value(flow_name, NULL))
    {
        job->flow = flow;
        taskExecuted(job, false);
    }
    else if (ojob)
    {
        ojob->deleteLater();
    }

}

void Flower::startJob(QString flow_name, QString topic, QVariant var)
{
    Flow* flow = flows[flow_name];
//    if (Flow* flow = flows[flow_name])
    if (flow)
    {
        startJob(flow, topic, var);
    }
}

Job* Flower::startJob(Flow* flow, QString topic, QVariant var)
{
    bool log = false;
    if (log) qDebug() << "STARTJOB: " << flow << " topic: " << topic << " var: " << var;
    Job* retjob = NULL;
    if (!flow) return retjob;
    retjob = new Job(idcnt++, flow, topic, var);
    if (!retjob) return NULL;
    retjob->setSourceDevice(hfs->devId());
    retjob->setOriginDevice(hfs->devId());
    jobs.insert(retjob->id, retjob);

    if (flow->exclusive)
    {
        if (flow->locked)    // flow is in execution phase, already enqueued, just return
        {
            return retjob;
        }
        else                // good to go with processing the flow
        {
           // flow->locked = true;
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

void Flower::taskExecuted(Job* job, bool step)
{
     bool log = true;
     if (log) qDebug() << "taskExecuted" << job << "  NR: " << hfs->nodeRole();
     if (!job || !job->flow) return; // should be handled as error
     int flow_length = job->flow->tasks.count();
     int job_step = step ? ++job->step : job->step;
     Flow* lookflow = nullptr;

     if (job_step < flow_length)      // we have not yet reached the end of the flow
     {
         if (Task* nexttask = job->flow->tasks.at(job_step))
         {
             QString path = nexttask->path();
             int self_devid = hfs->devId();

             if (!path.isEmpty())
             {
                  int task_devid = -1;                                          // return to the sender if we do not know anything about it
                  if (HFSItem* item = hfs->_hasPath(path, false))
                  {
                      if ((item->flags() & HFS_LocalUsage) != 0)
                      {
                          if (hfs->nodeRole() == NR_MASTER)                     // Bounce back to the caller
                          {
                              task_devid = job->originDevice();
                          }
                          else
                          {
                              task_devid = hfs->getDevIdFromPath(path);
                          }
                      }
                      else if ((item->flags() & HFS_GlobalUsage) != 0)          // If we are the master, we cannot delegate the job execution further
                      {
                          if (hfs->nodeRole() == NR_MASTER)
                          {
                              // task_devid = hfs->getDevIdFromPath(path);         // Currently is our own devid, but load balancer and failsafe should be built in here
                              task_devid = self_devid;
                          }
                          if (hfs->nodeRole() == NR_SLAVE)
                          {
                              task_devid = -1;                                  // Placeholder line: Falling back to send to master 
                          }
                      }

                      if (task_devid != -1 && self_devid == task_devid)                // Flow should be executed on the local node
                      {
                          QString executor_id = "gui";
                          if (Executor* executor = executors[executor_id])
                          {
                              QMetaObject::invokeMethod((QObject*)executor,
                                  "enqueueJob",
                                  Qt::QueuedConnection,
                                  Q_ARG(Job*, job));
                          }
                      }
                      else
                      {
                          qDebug() << "\tCURRENT TASK: " << nexttask->name() << " PATH: " << path;
                          qDebug() << " SELF DEVID: " << self_devid;
                          qDebug() << " TASK DEVID: " << task_devid;
                          qDebug() << "Flow should continue on remote node";
                          emit outBoundJob(job, task_devid);
                      }
                  }
                  else
                  {
                      qDebug() << "PATH is not provided " << path;
                      jobs.remove(job->id);
                      job->deleteLater();
                  }
             }
             else
             {
                 qDebug() << "EMPTY path ATM ";
                 jobs.remove(job->id);
                 job->deleteLater();
             }
        }
        else
        {
            qDebug() << "TASK NOT FOUND";
            jobs.remove(job->id);
            job->deleteLater();
        }
    }
    else                                // flow execution is finished, clear up!
    {
        if (job->flow->exclusive)
        {
            job->flow->locked = false;
            lookflow = job->flow;
        }
        jobs.remove(job->id);
        job->deleteLater();
        if (log) qDebug() << jobs.count() << " JOBS remaining";
    }

    Job* nextjob = nullptr;
    if (lookflow)
    {
        QHashIterator<int, Job* > it(jobs);
        while (it.hasNext() && !nextjob)
        {
            it.next();
            Job* jb = it.value();
            if (jb->flow == lookflow)
            {
                nextjob = jb;
            }
        }
    }

    if (nextjob)
    {
        QMetaObject::invokeMethod(this, "taskExecuted", Qt::QueuedConnection, Q_ARG(Job*, nextjob));
    }
}