/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef PROMETHEUS_H
#define PROMETHEUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class prometheus : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "prometheus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    prometheus();
    ~prometheus();

    QString name() 		{ return "prometheus"; }
    QString description()	{ return "Support for Prometheus metrics export."; }

protected:
    	void setup();
	void __init__();
	void handle_event();
	void _metric();
	void _sanitize_metric_name();
	void state_as_number();
	void _labels();
	void _battery();
	void _handle_binary_sensor();
	void _handle_input_boolean();
	void _handle_device_tracker();
	void _handle_person();
	void _handle_light();
	void _handle_lock();
	void _handle_climate();
	void _handle_sensor();
	void _sensor_default_metric();
	void _sensor_attribute_metric();
	void _sensor_override_metric();
	void _sensor_override_component_metric();
	void _sensor_fallback_metric();
	void _unit_string();
	void _handle_switch();
	void _handle_zwave();
	void _handle_automation();
	void __init__();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif