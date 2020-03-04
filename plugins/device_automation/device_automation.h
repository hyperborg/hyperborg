/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEVICE_AUTOMATION_H
#define DEVICE_AUTOMATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class device_automation : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "device_automation.json");
    Q_INTERFACES(HyPluginInterface);
public:
    device_automation();
    ~device_automation();

    QString name() 		{ return "device_automation"; }
    QString description()	{ return "Helpers for device automations."; }

protected:
    	void async_setup();
	void async_get_device_automation_platform();
	void _async_get_device_automations_from_domain();
	void _async_get_device_automations();
	void _async_get_device_automation_capabilities();
	void handle_device_errors();
	void with_error_handling();
	void websocket_device_automation_list_actions();
	void websocket_device_automation_list_conditions();
	void websocket_device_automation_list_triggers();
	void websocket_device_automation_get_action_capabilities();
	void websocket_device_automation_get_condition_capabilities();
	void websocket_device_automation_get_trigger_capabilities();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif