#ifndef hhc_n8i8op_H
#define hhc_n8i8op_H

#include <hyplugin.h>
#include <hyobject.h>
#include <tcpsocket.h>
#include "hhc_n8i8op_device.h"

#include <QString>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QDir>


class hhc_n8i8op : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hhc_n8i8op.json");
    Q_INTERFACES(HyPluginInterface);

public:
    hhc_n8i8op(QObject *parent=nullptr);
    ~hhc_n8i8op();

    QString name()          { return "hhc_n8i8op";                      }
    QString description()   { return "HHC-N8I8OP driver";               }
    int implementation()    { return Developement;                      }
    HyObject::Type type()   { return Plugin;                            }
    QObject *getObject()    { return this;                              }
    QString author()        { return "Imre, Nagy <i@hyperborg.com>";    }

    void init();

    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject &json);
    void setupDemo();

private:
    void clearDevices();

private:
    QList<hhc_n8i8op_device* > devices;
};


#endif