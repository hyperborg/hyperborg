/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZONE_H
#define ZONE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class zone : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zone.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zone();
    ~zone();

    QString name() 		{ return "zone"; }
    QString description()	{ return "Support for the definition of zones."; }

protected:
    	void async_active_zone();
	void in_zone();
	void  _process_create_data();
	void _get_suggested_id();
	void  _update_data();
	void  async_setup();
	void  _collection_changed();
	void  reload_service_handler();
	void  core_config_updated();
	void _home_conf();
	void  async_setup_entry();
	void  async_unload_entry();
	void __init__();
	void state();
	void name();
	void unique_id();
	void icon();
	void state_attributes();
	void  async_update_config();
	void _generate_attrs();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif