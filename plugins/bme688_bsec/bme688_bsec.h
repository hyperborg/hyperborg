#ifndef bme688_bsec_H
#define bme688_bsec_H

#include <hyplugin_interface.h>

#include "common.h"
#include "hfsitem.h"
#include "hplugin.h"
#include "hdevice.h"

class Job;


class BME688_BSEC : public HPlugin, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bme688_bsec.json");
    Q_INTERFACES(HyPluginInterface);

public:
    BME688_BSEC(QObject* parent = nullptr);
    ~BME688_BSEC();

    QString name() { return "BME688_BSEC"; }
    QString description() { return "BME688_BSEC driver"; }
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