/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TELLSTICK_H
#define TELLSTICK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class tellstick : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tellstick.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tellstick(QObject *parent=nullptr);
    ~tellstick();

    QString name() 		{ return "tellstick"; }
    QString description()	{ return "Support for Tellstick."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _discover();
	void setup();
	void stop_tellcore_net();
	void async_handle_callback();
	void clean_up_callback();
	void __init__();
	void async_added_to_hass();
	void should_poll();
	void assumed_state();
	void is_on();
	void _parse_ha_data();
	void _parse_tellcore_data();
	void _update_model();
	void _send_device_command();
	void _send_repeated_command();
	void _change_device_state();
	void turn_on();
	void turn_off();
	void _update_model_from_command();
	void update_from_callback();
	void _update_from_tellcore();
	void update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif