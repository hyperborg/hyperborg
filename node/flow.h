#ifndef FLOW_H
#define FLOW_H

#include "common.h"
#include "task.h"
#include "hfs_interface.h"

/*
    URL: <device>:<executor>:<path>

        device:     = . -> the local device, @->master device, *->all devices, id->given device  (default: master)
        executor    = . -> main gui thread, id->named executor                                   (default: main gui thread)
        path        = the actual path of the given object or function
*/

class Flow : public QObject
{
    Q_OBJECT
public:
    Flow(HFS_Interface* _hfs, QString _name) : hfs(_hfs), name(_name)
    {
        exclusive = true;
        locked = false;
    }
    ~Flow() {}

    Task* createTask(QString name, QString url, JobBounceType bounce=NoBounce)
    {
        if (Task* task = new Task(name, url, bonce))
        {
            addTask(task);
            return task;
        }
        return nullptr;
    }

    void addTask(Task* task) { tasks.append(task); }
    QString getName() { return name; }

public:
    QList<Task*> tasks;
    bool exclusive;             // Only 1 job should be traversing in this flow at a time
    bool locked;                // Only 1 Flower is expected to operate in an application, thus no guards are
    // needed for this flag.
    QString name;
    HFS_Interface* hfs;
};

#endif