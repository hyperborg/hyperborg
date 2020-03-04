/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EVOHOME_H
#define EVOHOME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class evohome : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "evohome.json");
    Q_INTERFACES(HyPluginInterface);
public:
    evohome();
    ~evohome();

    QString name() 		{ return "evohome"; }
    QString description()	{ return "Support for (EMEA/EU-based) Honeywell TCC climate systems."; }

protected:
    	void _local_dt_to_aware();
	void _dt_to_local_naive();
	void convert_until();
	void convert_dict();
	void convert_key();
	void _handle_exception();
	void  async_setup();
	void  load_auth_tokens();
	void setup_service_functions();
	void  force_refresh();
	void  set_system_mode();
	void  set_zone_override();
	void __init__();
	void  save_auth_tokens();
	void  call_client_api();
	void  _update_v1();
	void get_session_id();
	void  _update_v2();
	void  async_update();
	void __init__();
	void  async_refresh();
	void  async_tcs_svc_request();
	void  async_zone_svc_request();
	void should_poll();
	void unique_id();
	void name();
	void device_state_attributes();
	void icon();
	void supported_features();
	void  async_added_to_hass();
	void precision();
	void temperature_unit();
	void __init__();
	void current_temperature();
	void setpoints();
	void  _update_schedule();
	void  async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif