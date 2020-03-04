/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RAINMACHINE_H
#define RAINMACHINE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rainmachine : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rainmachine.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rainmachine();
    ~rainmachine();

    QString name() 		{ return "rainmachine"; }
    QString description()	{ return "Support for RainMachine devices."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void disable_program();
	void disable_zone();
	void enable_program();
	void enable_zone();
	void pause_watering();
	void start_program();
	void start_zone();
	void stop_all();
	void stop_program();
	void stop_zone();
	void unpause_watering();
	void async_unload_entry();
	void __init__();
	void _async_update_listener_action();
	void async_deregister_sensor_api_interest();
	void async_fetch_from_api();
	void async_register_sensor_api_interest();
	void async_update();
	void async_update_sensors();
	void async_update_programs_and_zones();
	void device_class();
	void device_info();
	void device_state_attributes();
	void should_poll();
	void _update_state();
	void async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif