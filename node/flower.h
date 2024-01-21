#ifndef FLOWER_H
#define FLOWER_H

#include "common.h"
#include "task.h"
#include "flow.h"
#include "job.h"
#include "hfs_interface.h"
#include "executor.h"

class HFS;

class Flower : public QObject
{
    Q_OBJECT
public:
    Flower(HFS* hfs, QObject* parent = nullptr);
    ~Flower();

    void addExecutor(QString name, Executor* exec);
    void addExecutor(Executor* exec);

    Flow* createFlow(QString name, QString triggertopic=QString())
    {
        if (Flow* retflow = new Flow((HFS_Interface *)hfs, name))
        {
            addFlow(retflow, name);
            if (!triggertopic.isNull())
            {
                addFlowTriggerEvent(retflow, triggertopic);
            }
            return retflow;
        }
        return nullptr;
    }

    void addFlowTriggerEvent(Flow* flow, QString topic);

signals:
    void outBoundJob(Job* job);

public slots:
    void startJob(QString topic, QVariant var, QString flow_name);
    void startJob(QString flow_name, QString topic = QString(), QVariant var = QVariant());
    Job* startJob(Flow* flow, QString topic = QString(), QVariant var = QVariant());
    void jobTransferred(Job* job);
    void taskExecuted(Job* job);
    void addFlow(Flow* flow, QString name = QString());

private:
    int idcnt;
    QString topic;
    QHash<QString, Executor*> executors;
    QHash<QString, Flow*> flows;
    QList<Job*> jobs;
    HFS* hfs;
};

#endif