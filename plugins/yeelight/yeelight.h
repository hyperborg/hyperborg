/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YEELIGHT_H
#define YEELIGHT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class yeelight : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yeelight.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yeelight();
    ~yeelight();

    QString name() 		{ return "yeelight"; }
    QString description()	{ return "Support for Xiaomi Yeelight WiFi color bulb."; }

protected:
    	void setup();
	void device_discovered();
	void update();
	void load_platforms();
	void _setup_device();
	void __init__();
	void bulb();
	void name();
	void config();
	void ipaddr();
	void available();
	void model();
	void is_nightlight_supported();
	void is_nightlight_enabled();
	void is_color_flow_enabled();
	void _active_mode();
	void _color_flow();
	void _nightlight_brightness();
	void type();
	void turn_on();
	void turn_off();
	void _update_properties();
	void _initialize_device();
	void update();
	void setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif