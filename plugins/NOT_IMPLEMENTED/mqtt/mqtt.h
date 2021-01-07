/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MQTT_H
#define MQTT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mqtt : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt(QObject *parent=nullptr);
    ~mqtt();

    QString name() 		{ return "mqtt"; }
    QString description()	{ return "Support for MQTT message handling."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void valid_topic();
	void valid_subscribe_topic();
	void valid_publish_topic();
	void validate_device_has_at_least_one_identifier();
	void embedded_broker_deprecated();
	void _build_publish_data();
	void publish();
	void async_publish();
	void publish_template();
	void wrap_msg_callback();
	void async_wrapper();
	void wrapper();
	void async_subscribe();
	void subscribe();
	void remove();
	void _async_setup_server();
	void _async_setup_discovery();
	void async_setup();
	void async_setup_entry();
	void async_stop_mqtt();
	void async_publish_service();
	void async_dump_service();
	void collect_msg();
	void write_dump();
	void finish_dump();
	void __init__();
	void async_connect();
	void async_disconnect();
	void stop();
	void async_remove();
	void _async_unsubscribe();
	void _async_perform_subscription();
	void _mqtt_on_connect();
	void _mqtt_on_message();
	void _mqtt_handle_message();
	void _mqtt_on_disconnect();
	void _raise_on_error();
	void _match_topic();
	void async_added_to_hass();
	void attributes_discovery_update();
	void _attributes_subscribe_topics();
	void attributes_message_received();
	void async_will_remove_from_hass();
	void device_state_attributes();
	void availability_discovery_update();
	void _availability_subscribe_topics();
	void availability_message_received();
	void available();
	void discovery_callback();
	void async_removed_from_registry();
	void device_info_from_config();
	void device_info_discovery_update();
	void device_info();
	void websocket_remove_device();
	void websocket_subscribe();
	void forward_messages();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif