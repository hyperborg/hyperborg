/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef XIAOMI_AQARA_H
#define XIAOMI_AQARA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class xiaomi_aqara : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "xiaomi_aqara.json");
    Q_INTERFACES(HyPluginInterface);
public:
    xiaomi_aqara();
    ~xiaomi_aqara();

    QString name() 		{ return "xiaomi_aqara"; }
    QString description()	{ return "Support for Xiaomi Gateways."; }

protected:
    	void _fix_conf_defaults();
	void setup();
	void xiaomi_gw_discovered();
	void stop_xiaomi();
	void play_ringtone_service();
	void stop_ringtone_service();
	void add_device_service();
	void remove_device_service();
	void __init__();
	void _add_push_data_job();
	void async_added_to_hass();
	void unique_id();
	void available();
	void should_poll();
	void device_state_attributes();
	void _async_set_unavailable();
	void _async_track_unavailable();
	void push_data();
	void parse_voltage();
	void parse_data();
	void _add_gateway_to_schema();
	void gateway();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif