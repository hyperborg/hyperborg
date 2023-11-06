#ifndef FLOWER_H
#define FLOWER_H

#include "common.h"
#include "task.h"
#include "flow.h"
#include "job.h"
#include "hfs_interface.h"
#include "executor.h"

class Flower : public QObject
{
    Q_OBJECT
public:
    Flower(HFS_Interface* hfs, QObject* parent = nullptr);
    ~Flower();

    void addExecutor(QString name, Executor* exec);
    void addExecutor(Executor* exec);

    void addFlow(Flow* flow, QString name = QString())
    {
        if (!flow) return;
        if (name.isEmpty()) name = flow->getName();
        flows.insert(name, flow);
    }

    Flow* createFlow(QString name, QString triggertopic)
    {
        if (Flow* retflow = new Flow(hfs, name))
        {
            addFlow(retflow);
            if (!triggertopic.isNull())
            {
                addFlowTriggerEvent(retflow, triggertopic);
            }
            return retflow;
        }
        return nullptr;
    }

    void addFlowTriggerEvent(Flow* flow, QString topic);

public slots:
    void startJob(QString topic, QVariant var, QString flow_name);
    Job* startJob(Flow* flow, QString topic = QString(), QVariant var = QVariant());
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