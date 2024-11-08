#ifndef dfr0971_H
#define dfr0971_H

#include <hyplugin_interface.h>

#include "common.h"
#include "hfsitem.h"
#include "hplugin.h"
#include "hdevice.h"
#include "dfr0971_device.h"

class Job;

class DFR0971 : public HPlugin, public HyPluginInterface
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

    void loadConfiguration(QString str);

signals:

public slots:

private:
    void clearDevices();

};

#endif