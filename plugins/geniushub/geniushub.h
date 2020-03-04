/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GENIUSHUB_H
#define GENIUSHUB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class geniushub : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geniushub.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geniushub();
    ~geniushub();

    QString name() 		{ return "geniushub"; }
    QString description()	{ return "Support for a Genius Hub system."; }

protected:
    	void  async_setup();
	void setup_service_functions();
	void  set_zone_mode();
	void __init__();
	void hub_uid();
	void  async_update();
	void make_debug_log_entries();
	void  async_added_to_hass();
	void  _refresh();
	void unique_id();
	void should_poll();
	void device_state_attributes();
	void current_temperature();
	void target_temperature();
	void min_temp();
	void max_temp();
	void temperature_unit();
	void supported_features();
	void  async_set_temperature();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif