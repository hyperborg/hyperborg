#ifndef JOB_H
#define JOB_H

#include <QString>
#include <QVariant>
#include <QStack>
#include <QPair>

#include "common.h"
#include "flow.h"

class Flower;

class Job : public QObject
{

friend class Flower;

Q_OBJECT
public:
    Job(int _id, Flow *_flow, QString _topic=QString(), QVariant _var=QVariant()) : flow(_flow), id(_id), step(-1), topic(_topic), variant(_var)
    {
        stack_push_counter = 0;
    }
    ~Job() {}

    QString save() {}
    void load() {}

public:
    int id;
    Flow* flow;
    int step;
    QString topic;
    QVariant variant;

protected:
    void enterTask()
    {
        stack_push_counter = 0;
    }
    void leaveTask()
    {
        stack_push_counter = 0;
    }

protected:
    int stack_push_counter;
    QStack<StackPair> stack;
};

#endif