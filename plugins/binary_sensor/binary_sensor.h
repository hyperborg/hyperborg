/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef BINARY_SENSOR_H
#define BINARY_SENSOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class binary_sensor : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "binary_sensor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    binary_sensor();
    ~binary_sensor();

    QString name() 		{ return "binary_sensor"; }
    QString description()	{ return "Component to interface with binary sensors."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void is_on();
	void state();
	void device_class();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif