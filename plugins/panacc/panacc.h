#ifndef PANACC_H
#define PANACC_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>
#include <QMap>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class PanaCC : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "panacc.json");
    Q_INTERFACES(HyPluginInterface);

public:
    PanaCC(QObject *parent=NULL);
    ~PanaCC();

    QString name()          { return "panacc";                         			}
    QString description()   { return "Panasonic Comfort Cloud communication bridge";    }
    int implementation()    { return Developement;                      		}
    QObject *getObject()    { return this;                              		}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   		}

    void init();
    QJsonObject configurationTemplate();
    void saveConfiguration(QJsonObject &json);
    bool loadConfiguration(QJsonObject json);

private:
    
};
#endif
