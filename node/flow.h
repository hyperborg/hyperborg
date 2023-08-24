#ifndef FLOW_H
#define FLOW_H

#include <QList>
#include <QString>

#include "common.h"
#include "task.h"

class Flow : public QObject
{
Q_OBJECT
public:
    Flow(QString _topic) 
    {
        topic = _topic;
        exclusive = true;
        locked = false;
    }
    ~Flow() {}

    Task* createTask(QString name, QString executor, QString topic, QString method)
    {
        if (Task* task = new Task(name, executor, topic, method))
        {
            addTask(task);
            return task;
        }
        return nullptr;
    }

    void addTask(Task* task) { tasks.append(task); }
    QString getTopic() { return topic; }

public:
    QList<Task*> tasks;
    bool exclusive;             // Only 1 job should be traversing in this flow at a time
    bool locked;                // Only 1 Flower is expected to operate in an application, thus no guards are
                                // needed for this flag.
    QString topic;
};

#endif