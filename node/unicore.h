#ifndef UNICORE_H
#define UNICORE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QWaitCondition>
#include <QMutex>
#include <QVector>
#ifndef WASM
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#endif

#include "buffer.h"
#include "common.h"
#include "entity.h"
#include "hsettings.h"


class UniCore : public QThread
{
Q_OBJECT
public:
    UniCore(QObject *parent=nullptr);
    ~UniCore();

    QWaitCondition* getWaitCondition();
    void setIncomingDataBuffer(DataBuffer* buffer) { databuffer = buffer; }
    void setIncomingPackBuffer(PackBuffer* buffer) { packbuffer = buffer; }

protected:
    void run();

public slots:
    void setRole(NodeCoreInfo info);

signals:
    void newPackReady(DataPack* pack);
    void newBlockReady(DataBlock* block);
    void logLine(int severity, QString str);

public slots:
    void init();

private:
    void log(int severity, QString line);
    int processDataFromCoreServer();
    int processPackFromSlotter();
    bool checkIntegrity(DataBlock* block);
    bool checkACL(DataBlock* block);
    bool checkWhatever(DataBlock* block);
    bool parseDataBlock(DataBlock* block);      // expand datablock into structured object
    bool constructDataBlock(DataBlock* block);  // build a datablock from a structured object
    bool executeDataBlock(DataBlock* block);    // House management "virtual CPU" main entry point

    bool connectToDatabase();
#ifndef WASM    
    // SQL TEST
    void queryTemperatureHistory();
#endif

private:
    HSettings* settings;
    bool bypass;
    QWaitCondition *waitcondition;
    QMutex* unicore_mutex;
    DataBuffer* databuffer;
    PackBuffer* packbuffer;

#ifndef WASM
    QSqlDatabase db;
    QSqlQuery* query;
    QSqlQuery* uquery;
#endif
}; 

#endif