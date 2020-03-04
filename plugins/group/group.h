/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GROUP_H
#define GROUP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class group : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "group.json");
    Q_INTERFACES(HyPluginInterface);
public:
    group();
    ~group();

    QString name() 		{ return "group"; }
    QString description()	{ return "Provide the functionality to group entities."; }

protected:
    	void _conf_preprocess();
	void _get_group_on_off();
	void is_on();
	void expand_entity_ids();
	void get_entity_ids();
	void groups_with_entity();
	void async_setup();
	void reload_service_handler();
	void locked_service_handler();
	void groups_service_handler();
	void _async_process_config();
	void __init__();
	void create_group();
	void async_create_group();
	void should_poll();
	void state();
	void icon();
	void state_attributes();
	void assumed_state();
	void update_tracked_entity_ids();
	void async_update_tracked_entity_ids();
	void async_start();
	void async_stop();
	void async_update();
	void async_added_to_hass();
	void async_will_remove_from_hass();
	void _async_state_changed_listener();
	void _tracking_states();
	void _async_update_group_state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif