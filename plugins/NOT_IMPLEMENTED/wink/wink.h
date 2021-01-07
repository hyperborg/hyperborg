/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WINK_H
#define WINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class wink : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wink(QObject *parent=nullptr);
    ~wink();

    QString name() 		{ return "wink"; }
    QString description()	{ return "Support for Wink hubs."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _request_app_setup();
	void wink_configuration_callback();
	void _request_oauth_completion();
	void setup();
	void _subscribe();
	void keep_alive_call();
	void start_subscription();
	void stop_subscription();
	void save_credentials();
	void force_update();
	void pull_new_devices();
	void set_pairing_mode();
	void rename_device();
	void delete_device();
	void nimbus_service_handle();
	void siren_service_handle();
	void __init__();
	void _pubnub_update();
	void unique_id();
	void available();
	void update();
	void should_poll();
	void device_state_attributes();
	void _battery_level();
	void _manufacturer_device_model();
	void _manufacturer_device_id();
	void _device_manufacturer();
	void _model_name();
	void _tamper();
	void async_added_to_hass();
	void state();
	void icon();
	void dial_attributes();
	void set_configuration();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif