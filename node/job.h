#ifndef JOB_H
#define JOB_H

#include "flow.h"
#include <QString>
#include <QVariant>
#include <QStack>


class Job : public QObject
{
    Q_OBJECT
public:
    Job(int _id, Flow* _flow, QString _topic = QString(), QVariant _var = QVariant()) : flow(_flow), id(_id), step(-1), topic(_topic), variant(_var)
    {
    }
    ~Job() {}

    Task* currentTask()
    {
        Task* rettask = NULL;
        if (!flow || step < 0 || (flow->tasks.count() < step)) return rettask;
        rettask = flow->tasks.at(step);
        return rettask;
    }

protected:

public:
    int id;
    Flow* flow;
    int step;
    QString topic;
    QVariant variant;

private:
    QStack<StackPair> stack;
};

#endif