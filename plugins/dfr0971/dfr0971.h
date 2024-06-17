#ifndef dfr0971_H
#define dfr0971_H

#include <hyplugin.h>
#include <hyobject.h>

#include "common.h"
#include "hfsitem.h"
#include "dfr0971_device.h"

class Job;


class DFR0971 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dfr0971.json");
    Q_INTERFACES(HyPluginInterface);

public:
    DFR0971(QObject* parent = nullptr);
    ~DFR0971();

    QString name() { return "DFR0971"; }
    QString description() { return "DFR0971 driver"; }
    int implementation() { return Developement; }
    QObject* getObject() { return this; }
    QString author() { return "Imre, Nagy <i@hyperborg.com>"; }

    void init();

signals:

public slots:

private:
    void clearDevices();

};

#endif