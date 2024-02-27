#ifndef SYSTEM_H
#define SYSTEM_H

#include <hyplugin.h>
#include <hyobject.h>

#include "common.h"

#include "hfsitem.h"

class Job;


class System : public HyObject, public HyPluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "system.json");
    Q_INTERFACES(HyPluginInterface);

public:
    System(QObject* parent = nullptr);
    ~System();

    QString name() { return "System"; }
    QString description() { return "System driver"; }
    int implementation() { return Developement; }
    QObject* getObject() { return this; }
    QString author() { return "Imre, Nagy <i@hyperborg.com>"; }

    void init();

public slots:
    QVariant function1(Job* job);
    QVariant function2(Job* job);
    QVariant function3(Job* job);

    QVariant updateAllCountInfo(Job *job);
    QVariant updateChart(Job *job);


private:
    void clearDevices();

};

#endif