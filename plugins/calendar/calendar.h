#ifndef Calendar_H
#define Calendar_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QStringList>

#include "common.h"
#include <hyplugin_interface.h>
#include "hplugin.h"
#include "hdevice.h"

class Calendar :  public HPlugin, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "calendar.json");
    Q_INTERFACES(HyPluginInterface);

public:
    Calendar(QObject *parent=NULL);
    ~Calendar();

    QString name()          { return "calendar";                                }
    QString description()   { return "General calendar plugin";                 }
    int implementation()    { return Developement;                              }
    QObject *getObject()    { return this;                                      }
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";           }

    void init();

public slots:
    void test() {}

};
#endif
