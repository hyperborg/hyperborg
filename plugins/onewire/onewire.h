/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ONEWIRE_H
#define ONEWIRE_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QStringList>
#include <QHash>
#include <QFile>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class onewire : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "onewire.json");
    Q_INTERFACES(HyPluginInterface);

public:
    onewire(QObject *parent=nullptr);
    ~onewire();

    QString name()          { return "onewire";                 }
    QString description()   { return "The onewire component.";  }
    int implementation()    { return Developement;              }
    HyObject::Type type()   { return Plugin;                    }
    QString author()        { return "Imre, Nagy";              }
    QObject *getObject()    { return this;                      }

    void init();
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

protected:
    void scanDevices();
    double readValue(QString id, int param);
    void writeValue(QString id);

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
    QString basedir;
};


#endif