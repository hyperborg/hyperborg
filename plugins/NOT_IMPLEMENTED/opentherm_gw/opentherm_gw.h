/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENTHERM_GW_H
#define OPENTHERM_GW_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class opentherm_gw : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "opentherm_gw.json");
    Q_INTERFACES(HyPluginInterface);
public:
    opentherm_gw(QObject *parent=nullptr);
    ~opentherm_gw();

    QString name() 		{ return "opentherm_gw"; }
    QString description()	{ return "Support for OpenTherm Gateway devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void options_updated();
	void async_setup_entry();
	void async_setup();
	void register_services();
	void reset_gateway();
	void set_control_setpoint();
	void set_dhw_ovrd();
	void set_device_clock();
	void set_gpio_mode();
	void set_led_mode();
	void set_max_mod();
	void set_outside_temp();
	void set_setback_temp();
	void async_unload_entry();
	void __init__();
	void cleanup();
	void connect_and_subscribe();
	void handle_report();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif