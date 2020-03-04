/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HOMEKIT_CONTROLLER_H
#define HOMEKIT_CONTROLLER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class homekit_controller : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "homekit_controller.json");
    Q_INTERFACES(HyPluginInterface);
public:
    homekit_controller();
    ~homekit_controller();

    QString name() 		{ return "homekit_controller"; }
    QString description()	{ return "Support for Homekit device discovery."; }

protected:
    	void escape_characteristic_name();
	void __init__();
	void  async_added_to_hass();
	void  async_will_remove_from_hass();
	void should_poll();
	void setup();
	void _setup_characteristic();
	void get_hk_char_value();
	void async_state_changed();
	void unique_id();
	void name();
	void available();
	void device_info();
	void get_characteristic_types();
	void  async_setup_entry();
	void  async_setup();
	void  async_unload_entry();
	void  async_remove_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif