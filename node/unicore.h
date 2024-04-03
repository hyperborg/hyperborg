#ifndef UNICORE_H
#define UNICORE_H

#include "buffer.h"
#include "common.h"
#include "hfs.h"

#include "task.h"
#include "flow.h"
#include "job.h"
#include "flower.h"

#include <QApplication>
#include <QMap>


class UniCore : public QThread
{
    Q_OBJECT
public:
    UniCore(HFS* hfs, QObject* parent = nullptr);
    ~UniCore();

    QWaitCondition* getWaitCondition();
    void setCSSidePackBuffer(PackBuffer* buffer) { databuffer = buffer; }   // incoming buffer on the CS stide
    void setSLSidePackBuffer(PackBuffer* buffer) { packbuffer = buffer; }   // incoming buffer on the SL side

signals:
    void newPackReadyForSL(DataPack* pack);
    void newPackReadyForCS(DataPack* pack);
    void HFS_outBound(DataPack* pack);

public slots:
    void init();
    QVariant nodeRoleChanged(Job *job);
    void HFS_inBound(DataPack* datapack);
    void dayEpochChanged(QVariant epoch_var);
    void addExecutor(QString prefix, Executor* executor);

    void loadLogic(QString filename) {}
    void saveLogic(QString filename) {}

protected slots:
    void setupFlowerBase();                 // Setup minimal structure for supporting flower system
    void reloadFlower();
    void outBoundJob(Job* job, int task_devid);

protected:
    void run();

private:
    void log(int severity, QString line);
    int processDataFromCoreServer();
    int processPackFromSlotter();
    bool checkIntegrity(DataPack* block);
    bool checkACL(DataPack* block);
    bool checkWhatever(DataPack* block);
    bool parseDataPack(DataPack* block);                        // expand DataPack into structured object
    bool processDataPack(DataPack* block, int local_source=1);  // role dependent path chooser 
    QString toEpoch(int hour, int min, int sec);

private:
    QWaitCondition* waitcondition;
    QMutex* unicore_mutex;
    PackBuffer* databuffer;
    PackBuffer* packbuffer;
    HFS* hfs;                       // HyperBorg File System

    // Flower related
    Flower* flower;
    QHash<QString, Flow*> flows;
    QHash<QString, Job*> jobs;
    Executor* fg_executor;          // Executor for foreground thread
    Executor* bg_executor;          // Executir for background thread
    QThread* bg_thread;

    QString _filename;
//    shared_ptr<BuildingModel> targetModel;

};

#endif