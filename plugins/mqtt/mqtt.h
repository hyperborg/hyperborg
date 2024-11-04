#ifndef MQTT_H
#define MQTT_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>
#include <QHash>
#include <QHashIterator>
#include <QByteArray>
#include <QDataStream>

#include "common.h"
#include "hdevice.h"
#include <hfs_interface.h>
#include <hfsitem.h>
#include <hyplugin_interface.h>

class mqtt : public HDevice, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt.json");
    Q_INTERFACES(HyPluginInterface);

public:
    mqtt(QObject *parent=nullptr);
    ~mqtt();

    QString name()          { return "MQTT";                           }
    QString description()   { return "MQTT Client Device Driver";      }
    int implementation()    { return Developement;                     }
    QObject *getObject()    { return this;                             }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";  }

    void init();

};
#endif
