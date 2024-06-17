#ifndef bme688_bsec_H
#define bme688_bsec_H

#include <hyplugin.h>
#include <hyobject.h>

#include "common.h"
#include "hfsitem.h"

class Job;


class BME688_BSEC : public HyObject, public HyPluginInterface
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

    void init();

signals:

public slots:

private:
    void clearDevices();

};

#endif