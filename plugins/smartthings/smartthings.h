/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SMARTTHINGS_H
#define SMARTTHINGS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class smartthings : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "smartthings.json");
    Q_INTERFACES(HyPluginInterface);
public:
    smartthings();
    ~smartthings();

    QString name() 		{ return "smartthings"; }
    QString description()	{ return "Support for SmartThings Cloud."; }

protected:
    	void  async_setup();
	void  async_migrate_entry();
	void  async_setup_entry();
	void  retrieve_device_status();
	void  async_get_entry_scenes();
	void  async_unload_entry();
	void  async_remove_entry();
	void __init__();
	void _assign_capabilities();
	void connect();
	void  regenerate_refresh_token();
	void disconnect();
	void get_assigned();
	void any_assigned();
	void  _event_handler();
	void __init__();
	void  async_added_to_hass();
	void  async_update_state();
	void  async_will_remove_from_hass();
	void device_info();
	void name();
	void should_poll();
	void unique_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif