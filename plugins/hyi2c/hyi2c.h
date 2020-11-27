#ifndef hyi2c_H
#define hyi2c_H

#include <hyplugin.h>
#include <hyobject.h>
#include <linux/i2c-dev.h>
#include <i2c/smbus.h>
#include "sys/ioctl.h"

#include <QString>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QDir>

#if 0

class HYI2C : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "HYI2C.json");
    Q_INTERFACES(HyPluginInterface);

#else
class HYI2C : public QObject
{
#endif

Q_OBJECT
public:
    HYI2C(QObject *parent=nullptr);
    ~HYI2C();
    QObject *getObject() { return this; };

    QString name() { return "HYI2C"; }
    QString description() { return "I2C Bus driver"; }
    int implementation() { return Developement; }

    void init();

protected:
    void scanI2CBuses();
    void scanI2CDevices(QString bus=QString());

    void setHyValue(QString bus, int address, int value);
    int  getHyValue(QString bus, int address);

private:

};


#endif