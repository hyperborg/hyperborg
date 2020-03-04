/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SMAPPEE_H
#define SMAPPEE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class smappee : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "smappee.json");
    Q_INTERFACES(HyPluginInterface);
public:
    smappee();
    ~smappee();

    QString name() 		{ return "smappee"; }
    QString description()	{ return "Support for Smappee energy monitor."; }

protected:
    	void setup();
	void __init__();
	void update();
	void is_remote_active();
	void is_local_active();
	void get_switches();
	void get_consumption();
	void get_sensor_consumption();
	void actuator_on();
	void actuator_off();
	void active_power();
	void active_cosfi();
	void instantaneous_values();
	void active_current();
	void active_voltage();
	void load_instantaneous();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif