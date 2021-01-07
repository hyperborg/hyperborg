/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RFLINK_H
#define RFLINK_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class rflink : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "rflink.json");
    Q_INTERFACES(HyPluginInterface);
public:
    rflink(QObject *parent=nullptr);
    ~rflink();

    QString name() 		{ return "rflink"; }
    QString description()	{ return "Support for Rflink devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void identify_event_type();
	void async_setup();
	void async_send_command();
	void event_callback();
	void reconnect();
	void connect();
	void __init__();
	void handle_event_callback();
	void _handle_event();
	void should_poll();
	void is_on();
	void assumed_state();
	void available();
	void _availability_callback();
	void async_added_to_hass();
	void set_rflink_protocol();
	void is_connected();
	void send_command();
	void _async_handle_command();
	void cancel_queued_send_commands();
	void _async_send_command();
	void async_turn_on();
	void async_turn_off();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif