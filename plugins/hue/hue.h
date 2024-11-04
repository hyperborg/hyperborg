/* HyperBorg House Management System
   Using Qt 6.8.0 (opensource)
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

#include <hyplugin_interface.h>
#include <common.h>
#include "hplugin.h"
#include "hdevice.h"
#include "hue_device.h"

class hue : public HPlugin, public HyPluginInterface
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
    QString author()        { return "Imre, Nagy <i@hyperborg.com>";        }
    QObject *getObject()    { return this;                                  }

public slots:
    void loadConfiguration(QString str);

protected:

private:

};


#endif