#ifndef hhc_n8i8op_H
#define hhc_n8i8op_H

#include <hyplugin_interface.h>
#include <tcpsocket.h>

#include "hdevice.h"
#include "hhc_n8i8op_device.h"

#include "common.h"

class hhc_n8i8op : public HDevice, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "hhc_n8i8op.json");
    Q_INTERFACES(HyPluginInterface);

public:
    hhc_n8i8op(QObject* parent = nullptr);
    ~hhc_n8i8op();

    QString name() { return "hhc_n8i8op"; }
    QString description() { return "HHC-N8I8OP driver"; }
    int implementation() { return Developement; }
    QObject* getObject() { return this; }
    QString author() { return "Imre, Nagy <i@hyperborg.com>"; }

    void loadConfiguration(QString str);

private:
    void clearDevices();

private:
    QList<hhc_n8i8op_device* > devices;
};

#endif