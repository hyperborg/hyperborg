#ifndef hyi2c_H
#define hyi2c_H

#include <hyplugin.h>
#include <hyobject.h>

#include <QString>
#include <QObject>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QDir>

class hyi2c : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hyi2c.json");
    Q_INTERFACES(HyPluginInterface);

public:
    hyi2c(QObject *parent=nullptr);
    ~hyi2c();
    QObject *getObject() { return this; };

    QString name() { return "hyi2c"; }
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