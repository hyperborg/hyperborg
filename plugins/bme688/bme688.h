#ifndef bme688_H
#define bme688_H

#include <hyplugin.h>
#include <hyobject.h>

#include "common.h"
#include "hfsitem.h"

class Job;


class BME688 : public HyObject, public HyPluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "bme688.json");
    Q_INTERFACES(HyPluginInterface);

public:
    BME688(QObject* parent = nullptr);
    ~BME688();

    QString name() { return "BME688"; }
    QString description() { return "BME688 driver"; }
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