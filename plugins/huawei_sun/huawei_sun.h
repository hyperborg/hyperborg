#ifndef HUAWEI_SUN_H
#define HUAWEI_SUN_H

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

class huawei_sun : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "huawei_sun.json");
    Q_INTERFACES(HyPluginInterface);

public:
    huawei_sun(QObject *parent=nullptr);
    ~huawei_sun();

    QString name()          { return "huawei_sun";                         		}
    QString description()   { return "Huawei Sun Solar Inverter Device Driver"; }
    int implementation()    { return Developement;                      	}
    QObject *getObject()    { return this;                              	}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   	}

    void init();

public slots:
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

private slots:

private:

private:

};
#endif
