#ifndef VCPU_H
#define VCPU_H

#include <QObject>
#include <QList>
#include <QHash>
#include <QVariant>

enum cmdType
{
    cmd = 0,
    set = 1
};

class vCmd
{
public:
    vCmd()  {}
    ~vCmd() {}

    virtual cmdType type() { return cmdType::cmd; }

public:
    int parnum;     // number of expected params
};

class vCmdSet : public vCmd
{
    vCmdSet()  {}
    ~vCmdSet() {}
    cmdType tyoe() { return cmdType::set; }
};

class vTask
{
public:
     vTask()
    {
    createSampleTask();
    }
    ~vTask() {}

    vCmd *getEntryCmd()
    {
    return cmds.count()?cmds.at(0):NULL;
    }

    void createSampleTask();

    QList<vCmd *> cmds;
};

class vScheduler;

class vJob
{
friend class vScheduler;
public:
    vJob(int _id)
    {
    id = _id;
    }
    ~vJob() {}

    int taskid;     // id of the task (program) this job is executing
    int taskfrag;   // id of the task fragment (part of task, that is assigned on this node)
    int nodeid;     // id of the node initiated the execution of the job
    int id;     // jobid, unique through entire system
    vTask *task;    // Task (or its fragment) this job is assigned to
    vCmd *cmd;      // current pointer pointing to the actual cmd in the task
    // input data should be stored here (format?)
    // stack should be stored here

protected:
    QList<QVariant> stack;
};

class vScheduler : public QObject
{
Q_OBJECT
public:
    vScheduler(QObject *parent=NULL);
    ~vScheduler();

    int proceedCnt() { return pcnt; }

signals:
    void signal_requestExecution(vJob *job);

public slots:
    void clearTask(int taskid);             // Clear a specific task and all associated jobs to it
    void clearTasks();                  // clears all task fragments on this node with all jobs currently running on them
    void addTask(int id, vTask *task, int frag=0);  // Add a task or task fragment (if frag>0, it is considered a task fragment)

    bool proceed();                 // returns true as long as it could proceed any jobs
    void requestExecution(vJob *job);           // do progress on an existing job

public slots: // should be private
    int createJob(int taskid);              // create a new job based on known task

private:
    int jidcnt;                     // incremental counter for assigning id for newly created jobs
    int pcnt;                       // proceed counter
    QHash<int, vTask*> tasks;
    QList<vJob*> jobs;
    vScheduler *bgsched;                // background task scheduler

};

#endif