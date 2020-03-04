/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AUTOMATION_H
#define AUTOMATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class automation : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "automation.json");
    Q_INTERFACES(HyPluginInterface);
public:
    automation();
    ~automation();

    QString name() 		{ return "automation"; }
    QString description()	{ return "Allow to set up simple automation rules via the config file."; }

protected:
    	void _platform_validator();
	void is_on();
	void automations_with_entity();
	void entities_in_automation();
	void automations_with_device();
	void devices_in_automation();
	void async_setup();
	void trigger_service_handler();
	void reload_service_handler();
	void __init__();
	void unique_id();
	void should_poll();
	void state_attributes();
	void referenced_devices();
	void referenced_entities();
	void async_added_to_hass();
	void async_turn_on();
	void async_turn_off();
	void async_trigger();
	void async_will_remove_from_hass();
	void async_enable();
	void async_enable_automation();
	void async_disable();
	void _async_attach_triggers();
	void remove_triggers();
	void device_state_attributes();
	void _async_process_config();
	void _async_process_if();
	void if_action();
	void _trigger_extract_device();
	void _trigger_extract_entities();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif