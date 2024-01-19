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
    Job(int _id, Flow* _flow, QString _topic = QString(), QVariant _var = QVariant()) 
        : flow(_flow), id(_id), step(-1), topic(_topic), variant(_var), _lastError(0)
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

    void setLastError(QVariant errid, QString errortext=QString())
    {
        _lastError = errid;
        _lastErrorText = errortext;
    }

    QVariant lastError()        { return _lastError;        }
    QString lastErrorText()     { return _lastErrorText;    }

    QString save();
    void load(QString str);

protected:
    QVariant _lastError;
    QString _lastErrorText;

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