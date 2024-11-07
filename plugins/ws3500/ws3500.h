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
#include "hplugin.h"
#include "hdevice.h"
#include "hactor.h"
#include "hsensor.h"
#include <hyplugin_interface.h>

#include "ws3500_device.h"

class ws3500 : public HPlugin, public HyPluginInterface
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

private:
    QHash<QString, HDevice *> devices;

};
#endif
