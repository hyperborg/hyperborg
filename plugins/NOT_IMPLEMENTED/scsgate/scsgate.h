/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SCSGATE_H
#define SCSGATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class scsgate : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "scsgate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    scsgate(QObject *parent=nullptr);
    ~scsgate();

    QString name() 		{ return "scsgate"; }
    QString description()	{ return "Support for SCSGate components."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void stop_monitor();
	void __init__();
	void handle_message();
	void devices();
	void add_device();
	void add_devices_to_register();
	void _activate_next_device();
	void is_device_registered();
	void start();
	void stop();
	void append_task();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif