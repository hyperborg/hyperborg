/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WATER_HEATER_H
#define WATER_HEATER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class water_heater : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "water_heater.json");
    Q_INTERFACES(HyPluginInterface);
public:
    water_heater(QObject *parent=nullptr);
    ~water_heater();

    QString name() 		{ return "water_heater"; }
    QString description()	{ return "Support for water heater devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void state();
	void precision();
	void capability_attributes();
	void state_attributes();
	void temperature_unit();
	void current_operation();
	void operation_list();
	void current_temperature();
	void target_temperature();
	void target_temperature_high();
	void target_temperature_low();
	void is_away_mode_on();
	void set_temperature();
	void async_set_temperature();
	void set_operation_mode();
	void async_set_operation_mode();
	void turn_away_mode_on();
	void async_turn_away_mode_on();
	void turn_away_mode_off();
	void async_turn_away_mode_off();
	void supported_features();
	void min_temp();
	void max_temp();
	void async_service_away_mode();
	void async_service_temperature_set();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif