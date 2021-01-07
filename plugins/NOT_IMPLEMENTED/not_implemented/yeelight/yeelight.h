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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class yeelight : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yeelight.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yeelight(QObject *parent=nullptr);
    ~yeelight();

    QString name() 		{ return "yeelight"; }
    QString description()	{ return "Support for Xiaomi Yeelight WiFi color bulb."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void device_discovered();
	void update();
	void load_platforms();
	void _setup_device();
	void __init__();
	void bulb();
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

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif