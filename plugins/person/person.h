/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class person : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "person.json");
    Q_INTERFACES(HyPluginInterface);
public:
    person();
    ~person();

    QString name() 		{ return "person"; }
    QString description()	{ return "Support for tracking people."; }

protected:
    	void  async_create_person();
	void  async_add_user_device_tracker();
	void  _async_migrate_func();
	void __init__();
	void  _async_load_data();
	void  async_load();
	void  _entity_registry_updated();
	void  _process_create_data();
	void _get_suggested_id();
	void  _update_data();
	void  _validate_user_id();
	void  filter_yaml_data();
	void  async_setup();
	void  _handle_user_removed();
	void  async_reload_yaml();
	void should_poll();
	void state();
	void state_attributes();
	void unique_id();
	void  async_added_to_hass();
	void  person_start_hass();
	void  async_update_config();
	void _async_handle_tracker_update();
	void _update_state();
	void _parse_source_state();
	void ws_list_person();
	void _get_latest();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif