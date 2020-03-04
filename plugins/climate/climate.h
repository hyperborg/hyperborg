/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef CLIMATE_H
#define CLIMATE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class climate : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "climate.json");
    Q_INTERFACES(HyPluginInterface);
public:
    climate();
    ~climate();

    QString name() 		{ return "climate"; }
    QString description()	{ return "Provides functionality to interact with climate devices."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void state();
	void precision();
	void capability_attributes();
	void state_attributes();
	void temperature_unit();
	void current_humidity();
	void target_humidity();
	void hvac_mode();
	void hvac_modes();
	void hvac_action();
	void current_temperature();
	void target_temperature();
	void target_temperature_step();
	void target_temperature_high();
	void target_temperature_low();
	void preset_mode();
	void preset_modes();
	void is_aux_heat();
	void fan_mode();
	void fan_modes();
	void swing_mode();
	void swing_modes();
	void set_temperature();
	void async_set_temperature();
	void set_humidity();
	void async_set_humidity();
	void set_fan_mode();
	void async_set_fan_mode();
	void set_hvac_mode();
	void async_set_hvac_mode();
	void set_swing_mode();
	void async_set_swing_mode();
	void set_preset_mode();
	void async_set_preset_mode();
	void turn_aux_heat_on();
	void async_turn_aux_heat_on();
	void turn_aux_heat_off();
	void async_turn_aux_heat_off();
	void async_turn_on();
	void async_turn_off();
	void supported_features();
	void min_temp();
	void max_temp();
	void min_humidity();
	void max_humidity();
	void async_service_aux_heat();
	void async_service_temperature_set();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif