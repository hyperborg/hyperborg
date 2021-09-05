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

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class ws3500 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ws3500.json");
    Q_INTERFACES(HyPluginInterface);

public:
    ws3500(QObject *parent=nullptr);
    ~ws3500();

    QString name()          { return "ws3500";                         		}
    QString description()   { return "WeatherStation for SainLogic WS3500";    	}
    int implementation()    { return Developement;                      	}
    HyObject::Type type()   { return Plugin;                            	}
    QObject *getObject()    { return this;                              	}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   	}

    void init();

public slots:
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

private slots:
    void newConnection();
    void parse(QString s);
    void readyRead();

private:
    bool convert(QString &value, QString &unit);

    bool splitKeyAndVal(QString src, QString& key, QString& val);
    bool checkAccess(QString id, QString passwd);

private:
    QTcpServer *server;
    QStringList keys;
    QStringList keyswu;	// keys that should have units
    QStringList units;
    QList<QTcpSocket *> sockets;	// keep tracking sockets-> socket could be opened but not sending data in!
    QHash<QString, HEntity *> entities;

};
#endif
