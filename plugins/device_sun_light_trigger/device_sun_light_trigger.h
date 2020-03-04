/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEVICE_SUN_LIGHT_TRIGGER_H
#define DEVICE_SUN_LIGHT_TRIGGER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class device_sun_light_trigger : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "device_sun_light_trigger.json");
    Q_INTERFACES(HyPluginInterface);
public:
    device_sun_light_trigger();
    ~device_sun_light_trigger();

    QString name() 		{ return "device_sun_light_trigger"; }
    QString description()	{ return "Support to turn on lights based on the states."; }

protected:
    	void  async_setup();
	void anyone_home();
	void any_light_on();
	void calc_time_for_light_when_sunset();
	void  async_turn_on_before_sunset();
	void async_turn_on_factory();
	void  async_turn_on_light();
	void schedule_light_turn_on();
	void check_light_on_dev_state_change();
	void turn_off_lights_when_all_leave();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif