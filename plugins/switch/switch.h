/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SWITCH_H
#define SWITCH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class switch : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "switch.json");
    Q_INTERFACES(HyPluginInterface);
public:
    switch();
    ~switch();

    QString name() 		{ return "switch"; }
    QString description()	{ return "Component to interface with switches that can be controlled remotely."; }

protected:
    	void is_on();
	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void current_power_w();
	void today_energy_kwh();
	void is_standby();
	void state_attributes();
	void device_class();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif