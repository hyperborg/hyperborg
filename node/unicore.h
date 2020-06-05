#ifndef UNICORE_H
#define UNICORE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>

#include <common.h>
#include <entity.h>
#include "hsettings.h"

#include <QWaitCondition>
#include <QMutex>
#include <QVector>
#include <QThread>

class UniCore : public QThread
{
Q_OBJECT
public:
    UniCore(QObject *parent=nullptr);
    ~UniCore();

    DataBlock* getOutgoingData();

protected:
    void run();

public slots:
    void incomingData(DataBlock* block);
    void setRole(NodeCoreInfo info);

signals:
    void outgoingDataAvailable();
    void logLine(int severity, QString str);

public slots:
    void init();

private:
    void log(int severity, QString line);
    void processIncomingData();
    void processIncomingHEvent();
    bool checkIntegrity(DataBlock* block);
    bool checkACL(DataBlock* block);
    bool checkWhatever(DataBlock* block);
    bool parseDataBlock(DataBlock* block);      // expand datablock into structured object
    bool constructDataBlock(DataBlock* block);  // build a datablock from a structured object

private:
    bool bypass;
    QWaitCondition *waitcondition;
    QMutex* id_mutex;   // mutex for incoming data buffer
    QMutex* od_mutex;   // mutex for outgoing data buffer
    QVector<DataBlock*> id_buffer;
    QVector<DataBlock*> od_buffer;
}; 

#endif