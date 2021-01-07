/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SENSE_H
#define SENSE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class sense : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sense.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sense(QObject *parent=nullptr);
    ~sense();

    QString name() 		{ return "sense"; }
    QString description()	{ return "Support for monitoring a Sense energy sensor."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void __init__();
	void set_devices_data();
	void get_device_by_id();
	void async_setup();
	void async_setup_entry();
	void async_sense_update();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif