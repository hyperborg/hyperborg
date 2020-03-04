/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FIBARO_H
#define FIBARO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fibaro : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fibaro.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fibaro();
    ~fibaro();

    QString name() 		{ return "fibaro"; }
    QString description()	{ return "Support for the Fibaro devices."; }

protected:
    	void __init__();
	void connect();
	void enable_state_handler();
	void disable_state_handler();
	void _on_state_change();
	void register();
	void get_children();
	void get_siblings();
	void _map_device_to_type();
	void _read_scenes();
	void _read_devices();
	void setup();
	void stop_fibaro();
	void async_added_to_hass();
	void _update_callback();
	void level();
	void level2();
	void dont_know_message();
	void set_level();
	void set_level2();
	void call_turn_on();
	void call_turn_off();
	void call_set_color();
	void action();
	void current_power_w();
	void current_binary_state();
	void unique_id();
	void should_poll();
	void update();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif