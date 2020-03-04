/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ABODE_H
#define ABODE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class abode : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "abode.json");
    Q_INTERFACES(HyPluginInterface);
public:
    abode();
    ~abode();

    QString name() 		{ return "abode"; }
    QString description()	{ return "Support for the Abode Security System."; }

protected:
    	void __init__();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void setup_hass_services();
	void change_setting();
	void capture_image();
	void trigger_quick_action();
	void  setup_hass_events();
	void logout();
	void setup_abode_events();
	void event_callback();
	void __init__();
	void  async_added_to_hass();
	void  async_will_remove_from_hass();
	void should_poll();
	void update();
	void name();
	void device_state_attributes();
	void unique_id();
	void device_info();
	void _update_callback();
	void __init__();
	void  async_added_to_hass();
	void should_poll();
	void update();
	void name();
	void device_state_attributes();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif