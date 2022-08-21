#ifndef UNICORE_H
#define UNICORE_H

#include <QObject>
#include <QString>
#include <QThread>
#include <QTimer>
#include <QWaitCondition>
#include <QMutex>
#include <QVector>
#include <QFile>
#include <QStringList>
#include <QJsonDocument>
#include <QByteArray>
#include <QVariant>

#include "buffer.h"
#include "common.h"
#include "hfs.h"


class UniCore : public QThread
{
Q_OBJECT
public:
    UniCore(HFS *hfs, QObject *parent=nullptr);
    ~UniCore();

    QWaitCondition* getWaitCondition();
    void setCSSidePackBuffer(PackBuffer* buffer) { databuffer = buffer; }   // incoming buffer on the CS stide
    void setSLSidePackBuffer(PackBuffer* buffer) { packbuffer = buffer; }   // incoming buffer on the SL side

public slots:
    void init();
    void setElementProperty(QString path, QVariant var, int col=0);

protected:
    void run();
    bool loadConfiguration(QJsonObject &json);
    bool saveConfiguration(QJsonObject& json);

signals:
    void newPackReadyForSL(DataPack* pack);
    void newPackReadyForCS(DataPack* block);

private:
    void log(int severity, QString line);
    int processDataFromCoreServer();
    int processPackFromSlotter();
    bool checkIntegrity(DataPack* block);
    bool checkACL(DataPack* block);
    bool checkWhatever(DataPack* block);
    bool parseDataPack(DataPack* block);      // expand DataPack into structured object
    bool constructDataPack(DataPack* block);  // build a DataPack from a structured object
    bool processDataPack(DataPack *block, bool down=true);    // role dependent path chooser
					      // down=true -> pack from SL, down=false -> pack from CS	
    bool executeDataPack(DataPack* block, bool down=true);    // House management "virtual CPU" main entry point

    void testSetup();

private:
    bool bypass;
    QWaitCondition *waitcondition;
    QMutex* unicore_mutex;
    PackBuffer* databuffer;
    PackBuffer* packbuffer;
    HFS* hfs;
};

#endif