/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SCRIPT_H
#define SCRIPT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class script : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "script.json");
    Q_INTERFACES(HyPluginInterface);
public:
    script();
    ~script();

    QString name() 		{ return "script"; }
    QString description()	{ return "Support for scripts."; }

protected:
    	void is_on();
	void scripts_with_entity();
	void entities_in_script();
	void scripts_with_device();
	void devices_in_script();
	void  async_setup();
	void  reload_service();
	void  turn_on_service();
	void  turn_off_service();
	void  toggle_service();
	void  _async_process_config();
	void  service_handler();
	void __init__();
	void should_poll();
	void state_attributes();
	void  async_turn_on();
	void  async_turn_off();
	void  async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif