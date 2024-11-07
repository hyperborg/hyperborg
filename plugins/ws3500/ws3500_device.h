#ifndef WS3500_DEVICE_H
#define WS3500_DEVICEH

#include "common.h"
#include "hdevice.h"

#include <QObject>
#include <QString>
#include <QStringList>
#include <QTcpServer>

class WS3500_Device : public HDevice
{
Q_OBJECT
public:
    WS3500_Device(QObject *parent = nullptr);
    ~WS3500_Device();

public slots:
    void loadConfiguration(QString str);

private slots:
    void shutdown();
    void newConnection();
    void parse(QString s);
    void readyRead();

private:
    void loadSensorInfos();
    bool splitKeyAndVal(QString src, QString& key, QString& val);
    bool checkAccess(QString id, QString passwd);
    HActor *getActor(QString key, QString value);

private:
    QTcpServer *server;
    QList<QTcpSocket *> sockets;        // keep tracking sockets-> socket could be opened but not sending data in!


    QString devid;                      // Device sends these credentials (we check them so no crafted data should be procesed)
    QString passwd;                     // filled from loadConfiguration
    QHash<QString, QString> pbuffer;    // Parsing buffer
    QHash<QString, SensorInfo> sensorinfos;

};
#endif
