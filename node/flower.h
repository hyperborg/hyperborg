#ifndef FLOWER_H
#define FLOWER_H

#include "hfs_interface.h"
#include "executor.h"
#include "flow.h"
#include "job.h"

class Flower : public QObject
{
Q_OBJECT
public:
    Flower(HFS_Interface *hfs, QObject *parent=nullptr);
    ~Flower();

    void addExecutor(QString name, Executor* exec);
    void addExecutor(Executor* exec);
    void addFlow(Flow* flow, QString topic=QString()) 
    { 
        if (flow) return;
        if (topic.isEmpty()) topic = flow->getTopic();
        flows.insert(topic, flow); 
    }

    Flow* createFlow(QString topic)
    {
        if (Flow* retflow = new Flow(topic))
        {
            flows.insert(topic, retflow);
            return retflow;
        }
        return nullptr;
    }

public slots:
    void startJob(QString topic, QVariant var);
    void startJob(Job* job);
    Job *startJob(Flow *flow, QString topic=QString(), QVariant var=QVariant());
    void taskExecuted(Job* job);

private:
    int idcnt;
    QString topic;
    QHash<QString, Executor*> executors;
    QHash<QString, Flow*> flows;
    QList<Job*> jobs;
    HFS_Interface* hfs;
};

#endif