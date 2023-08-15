#ifndef JOB_H
#define JOB_H

#include "flow.h"
#include <QString>
#include <QVariant>

class Job : public QObject
{
Q_OBJECT
public:
    Job(int _id, Flow *_flow, QString _topic=QString(), QVariant _var=QVariant()) : flow(_flow), id(_id), step(-1), topic(_topic), variant(_var)
    {
    }
    ~Job() {}

public:
    int id;
    Flow* flow;
    int step;
    QString topic;
    QVariant variant;
};


#endif