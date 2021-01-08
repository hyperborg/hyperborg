/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HUE_H
#define HUE_H

#include <QDir>
#include <QFile>
#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>
#include <QJsonObject>
#include <QJsonArray>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include "hue_device.h"

class hue : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hue.json");
    Q_INTERFACES(HyPluginInterface);

public:
    hue(QObject *parent=nullptr);
    ~hue();

    QString name()          { return "hue";                                 }
    QString description()   { return "Support for the Philips Hue system."; }
    int implementation()    { return Developement;                          }
    HyObject::Type type()   { return Plugin;                                }
    QString author()        { return "Imre, Nagy <i@hyperborg.com>";        }
    QObject *getObject()    { return this;                                  }

    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject &json);

public slots:
    void init();
    void setup();

protected:

private:

};


#endif