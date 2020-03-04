/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FAN_H
#define FAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fan : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fan.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fan();
    ~fan();

    QString name() 		{ return "fan"; }
    QString description()	{ return "Provides functionality to interact with fans."; }

protected:
    	void is_on();
	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void set_speed();
	void  async_set_speed();
	void set_direction();
	void  async_set_direction();
	void turn_on();
	void  async_turn_on();
	void oscillate();
	void  async_oscillate();
	void speed();
	void speed_list();
	void current_direction();
	void capability_attributes();
	void state_attributes();
	void supported_features();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif