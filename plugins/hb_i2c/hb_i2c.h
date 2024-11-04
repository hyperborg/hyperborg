#ifndef hb_i2c_H
#define hb_i2c_H

#include <hyplugin_interface.h>

#include "common.h"
#include "hfsitem.h"

#include "hplugin.h"
#include "hdevice.h"

#ifdef LINUX
extern "C"
{
    #include <linux/i2c-dev.h>
    #include <i2c/smbus.h>
}
#endif

class Job;

class HB_I2C :  public HPlugin, public HyPluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hb_i2c.json");
    Q_INTERFACES(HyPluginInterface);

public:
    HB_I2C(QObject* parent = nullptr);
    ~HB_I2C();

    QString name() { return "HB_I2C"; }
    QString description() { return "HB_I2C driver"; }
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