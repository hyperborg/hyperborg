/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NEST_H
#define NEST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class nest : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nest.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nest();
    ~nest();

    QString name() 		{ return "nest"; }
    QString description()	{ return "Support for Nest devices."; }

protected:
    	void nest_update_event_broker();
	void  async_setup();
	void  async_setup_entry();
	void validate_structures();
	void set_away_mode();
	void set_eta();
	void cancel_eta();
	void start_up();
	void shut_down();
	void __init__();
	void initialize();
	void structures();
	void thermostats();
	void smoke_co_alarms();
	void cameras();
	void _devices();
	void unit_of_measurement();
	void should_poll();
	void unique_id();
	void device_info();
	void update();
	void  async_added_to_hass();
	void  async_update_state();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif