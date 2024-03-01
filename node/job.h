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
    Job(int _id = -1, Flow* _flow = NULL, QString _topic = QString(), QVariant _var = QVariant())
        : flow(_flow), id(_id), step(-1), topic(_topic),
        variant(_var), _lastError(0), _src_device(-1), _dst_device(-1),
        _org_device(-1)
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

    void setDestinationDevice(int dd)   { _dst_device = dd;     }
    void setSourceDevice(int sd)        { _src_device = sd;     }
    void setOriginDevice(int od)        { _org_device = od;     }
    int sourceDevice()                  { return _src_device;   }
    int destinationDevice()             { return _dst_device;   }
    int originDevice()                  { return _org_device;   } 

protected:
    QVariant _lastError;
    QString _lastErrorText;

public:
    int id;
    Flow* flow;
    QString flow_name;
    int step;
    QString topic;
    QVariant variant;

private:
    QStack<StackPair> stack;
    int _org_device;    // Job originator device
    int _src_device;
    int _dst_device;
};

#endif