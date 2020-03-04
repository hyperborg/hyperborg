/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RFXTRX_H
#define RFXTRX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class rfxtrx : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rfxtrx.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rfxtrx();
    ~rfxtrx();

    QString name() 		{ return "rfxtrx"; }
    QString description()	{ return "Support for RFXtrx devices."; }

protected:
    	void setup();
	void handle_receive();
	void _start_rfxtrx();
	void _shutdown_rfxtrx();
	void get_rfx_object();
	void get_pt2262_deviceid();
	void get_pt2262_cmd();
	void get_pt2262_device();
	void find_possible_pt2262_device();
	void get_devices_from_config();
	void get_new_device();
	void apply_received_command();
	void __init__();
	void async_added_to_hass();
	void should_poll();
	void should_fire_event();
	void is_on();
	void assumed_state();
	void turn_off();
	void update_state();
	void _send_command();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif