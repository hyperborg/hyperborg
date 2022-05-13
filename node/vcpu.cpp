#include "vcpu.h"

/* sample program:

*/

void vTask::createSampleTask()
{
    
}

vScheduler::vScheduler(QObject *parent) : QObject(parent),
jidcnt(0), pcnt(1)
{
}

vScheduler::~vScheduler()
{
}

void vScheduler::clearTask(int taskid)
{
}

void vScheduler::clearTasks()
{
}

void vScheduler::addTask(int id, vTask *task, int frag)
{
    clearTask(id);
    tasks.insert(id, task);
}

void vScheduler::requestExecution(vJob *job)
{
}


int vScheduler::createJob(int taskid)
{
    int jid=-1;
    if (!tasks.contains(taskid)) return jid;
    vTask *task = tasks.value(taskid);
    if (!task) return jid;
    jid = jidcnt++;
    vJob *job = new vJob(jid);
    jobs.insert(jid, job);
    job->taskid = taskid;
    job->cmd=task->getEntryCmd();
    // job->taskfrag = 0;
    // job->nodeid   = 0;
    

    return jid;
}

bool vScheduler::proceed()
{
    pcnt++;
    if (jobs.empty()) return false;
    vJob *job = jobs.takeFirst();
    if (!job) return false;
    return true;
}
