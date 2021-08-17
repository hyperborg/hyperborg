#ifndef WS_H
#define WS_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>

#include <QHostAddress>
#include <QTctServer>
#include <QTcpSocket>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class WS : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ws.json");
    Q_INTERFACES(HyPluginInterface);

public:
    WS(QObject *parent=NULL);
    ~WS();

    QString name()          { return "WeatherStation";                         	}
    QString description()   { return "WeatherStation for SainLogic WS3500";    	}
    int implementation()    { return Developement;                      	}
    HyObject::Type type()   { return Plugin;                            	}
    QObject *getObject()    { return this;                              	}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   	}

    void init()             {}
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject &json);

private slots:
    void newConnection();
    void parse(QString s);

private:
    void init();
    bool convert(QString &value, &unit);

private:
    QTcpServer *server;
    QStringList keys;
    QStringList keyswu;	// keys that should have units
    QStringList units;

};
#endif
