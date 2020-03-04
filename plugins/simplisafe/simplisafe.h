/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SIMPLISAFE_H
#define SIMPLISAFE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class simplisafe : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "simplisafe.json");
    Q_INTERFACES(HyPluginInterface);
public:
    simplisafe();
    ~simplisafe();

    QString name() 		{ return "simplisafe"; }
    QString description()	{ return "Support for SimpliSafe alarm systems."; }

protected:
    	void _async_save_refresh_token();
	void async_register_base_station();
	void async_setup();
	void async_setup_entry();
	void verify_system_exists();
	void decorator();
	void v3_only();
	void remove_pin();
	void set_pin();
	void set_system_properties();
	void async_unload_entry();
	void __init__();
	void _on_connect();
	void _on_disconnect();
	void _on_event();
	void async_websocket_connect();
	void _async_process_new_notifications();
	void async_init();
	void refresh();
	void async_update();
	void update_system();
	void available();
	void device_info();
	void device_state_attributes();
	void unique_id();
	void _async_should_ignore_websocket_event();
	void async_added_to_hass();
	void update();
	void async_update_from_rest_api();
	void _async_internal_update_from_websocket_event();
	void async_update_from_websocket_event();
	void async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif