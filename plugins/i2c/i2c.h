#ifndef i2c_H
#define i2c_H

#include <hyplugin.h>
#include <hyobject.h>

#include "common.h"
#include "hfsitem.h"

class Job;


class I2C : public HyObject, public HyPluginInterface
{
    Q_OBJECT
        Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "i2c.json");
    Q_INTERFACES(HyPluginInterface);

public:
    I2C(QObject* parent = nullptr);
    ~I2C();

    QString name() { return "I2C"; }
    QString description() { return "I2C driver"; }
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