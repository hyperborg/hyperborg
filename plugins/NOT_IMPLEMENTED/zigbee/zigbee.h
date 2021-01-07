/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZIGBEE_H
#define ZIGBEE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class zigbee : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zigbee.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zigbee(QObject *parent=nullptr);
    ~zigbee();

    QString name() 		{ return "zigbee"; }
    QString description()	{ return "Support for Zigbee devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void _frame_received();
	void close_serial_port();
	void frame_is_relevant();
	void __init__();
	void address();
	void should_poll();
	void pin();
	void boolean_maps();
	void bool2state();
	void state2bool();
	void max_voltage();
	void async_added_to_hass();
	void handle_frame();
	void config();
	void is_on();
	void update();
	void _set_state();
	void turn_on();
	void turn_off();
	void state();
	void unit_of_measurement();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif