/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ESPHOME_H
#define ESPHOME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class esphome : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "esphome.json");
    Q_INTERFACES(HyPluginInterface);
public:
    esphome();
    ~esphome();

    QString name() 		{ return "esphome"; }
    QString description()	{ return "Support for esphome devices."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void on_stop();
	void async_on_state();
	void async_on_service_call();
	void send_home_assistant_state();
	void async_on_state_subscription();
	void on_login();
	void complete_setup();
	void _setup_auto_reconnect_logic();
	void try_connect();
	void _async_setup_device_registry();
	void _register_service();
	void execute_service();
	void _setup_services();
	void _cleanup_instance();
	void async_unload_entry();
	void platform_async_setup_entry();
	void async_list_entities();
	void async_entity_state();
	void esphome_state_property();
	void _wrapper();
	void __init__();
	void from_esphome();
	void from_hass();
	void esphome_map_enum();
	void async_added_to_hass();
	void _on_state_update();
	void _on_device_update();
	void async_will_remove_from_hass();
	void _entry_data();
	void _static_info();
	void _device_info();
	void _client();
	void _state();
	void available();
	void unique_id();
	void device_info();
	void should_poll();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif