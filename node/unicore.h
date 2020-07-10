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
    void setCSSidePackBuffer(PackBuffer* buffer) { databuffer = buffer; }   // incoming buffer on the CS stide
    void setSLSidePackBuffer(PackBuffer* buffer) { packbuffer = buffer; }   // incoming buffer on the SL side

protected:
    void run();

public slots:
    void setRole(NodeCoreInfo info);

signals:
    void newPackReady(DataPack* pack);
    void newBlockReady(DataPack* block);
    void logLine(int severity, QString str);

public slots:
    void init();

private:
    void log(int severity, QString line);
    int processDataFromCoreServer();
    int processPackFromSlotter();
    bool checkIntegrity(DataPack* block);
    bool checkACL(DataPack* block);
    bool checkWhatever(DataPack* block);
    bool parseDataPack(DataPack* block);      // expand DataPack into structured object
    bool constructDataPack(DataPack* block);  // build a DataPack from a structured object
    bool executeDataPack(DataPack* block);    // House management "virtual CPU" main entry point

    bool connectToDatabase();
    void queryTemperatureHistory();

    void testSetup();
    int serialize(DataPack *block);
    int deserialize(DataPack *block);

private:
    HSettings* settings;
    bool bypass;
    QWaitCondition *waitcondition;
    QMutex* unicore_mutex;
    PackBuffer* databuffer;
    PackBuffer* packbuffer;

#ifndef WASM
    QSqlDatabase db;
    QSqlQuery* query;
    QSqlQuery* uquery;
#endif
}; 

#endif