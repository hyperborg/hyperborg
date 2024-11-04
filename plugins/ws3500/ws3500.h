#ifndef WS3500_H
#define WS3500_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>

#include <QHostAddress>
#include <QTcpServer>
#include <QTcpSocket>
#include <QHash>

#include "common.h"
#include "hdevice.h"
#include "hsensor.h"
#include <hyplugin_interface.h>

class ws3500 : public HDevice, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ws3500.json");
    Q_INTERFACES(HyPluginInterface);

public:
    ws3500(QObject *parent=nullptr);
    ~ws3500();

    QString name()          { return "ws3500";                              }
    QString description()   { return "WeatherStation for SainLogic WS3500"; }
    int implementation()    { return Developement;                          }
    QObject *getObject()    { return this;                                  }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";       }

    void loadConfiguration(QString str);

protected:
    void loadSensorInfos();

private slots:
    void newConnection();
    void parse(QString s);
    void readyRead();

private:
    bool checkAccess(QString id, QString passwd);

private:
    QTcpServer *server;
    QStringList keys;
    QStringList keyswu; // keys that should have units
    QList<Unit> hunits;
    QStringList units;
    QStringList postfixs;
    QList<QTcpSocket *> sockets;    // keep tracking sockets-> socket could be opened but not sending data in!
    QString _pathbase;
    QString _sessionid;
    int parsecnt; 

    QHash<QString, SensorInfo> sensorinfos;
    QHash<QString, HSensor*> sensors;

};
#endif
