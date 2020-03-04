/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VACUUM_H
#define VACUUM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class vacuum : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vacuum.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vacuum();
    ~vacuum();

    QString name() 		{ return "vacuum"; }
    QString description()	{ return "Support for vacuum cleaner robots (botvacs)."; }

protected:
    	void is_on();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void supported_features();
	void battery_level();
	void fan_speed();
	void fan_speed_list();
	void stop();
	void  async_stop();
	void return_to_base();
	void  async_return_to_base();
	void clean_spot();
	void  async_clean_spot();
	void locate();
	void  async_locate();
	void set_fan_speed();
	void  async_set_fan_speed();
	void send_command();
	void  async_send_command();
	void status();
	void battery_icon();
	void capability_attributes();
	void state_attributes();
	void turn_on();
	void  async_turn_on();
	void turn_off();
	void  async_turn_off();
	void start_pause();
	void  async_start_pause();
	void  async_pause();
	void  async_start();
	void state();
	void battery_icon();
	void capability_attributes();
	void state_attributes();
	void start();
	void  async_start();
	void pause();
	void  async_pause();
	void  async_turn_on();
	void  async_turn_off();
	void  async_toggle();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif