#ifndef TickTock_H
#define TickTock_H

#include <QObject>
#include <QtPlugin>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QDateTime>

#include "common.h"
#include <hyplugin.h>
#include <hyobject.h>

class TickTock : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ticktock.json");
    Q_INTERFACES(HyPluginInterface);

public:
    TickTock(QObject *parent=NULL);
    ~TickTock();

    QString name()          { return "ticktock";                       			}
    QString description()   { return "TickTock Universal heartbeat and scheduler  ";    }
    int implementation()    { return Developement;                      		}
    QObject *getObject()    { return this;                              		}
    QString author()        { return "Imre, Nagy  <i@hyperborg.com>";   		}

    void init();

protected slots:
    void slot_timeout();

private:
    QTimer *timer;
    QDateTime dto;
    QDateTime dtn;
    int _dayepoch;
    int _epoch;

};
#endif
