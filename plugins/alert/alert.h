/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ALERT_H
#define ALERT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class alert : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "alert.json");
    Q_INTERFACES(HyPluginInterface);
public:
    alert();
    ~alert();

    QString name() 		{ return "alert"; }
    QString description()	{ return "Support for repeating alerts when conditions are met."; }

protected:
    	void is_on();
	void async_setup();
	void async_handle_alert_service();
	void __init__();
	void should_poll();
	void state();
	void hidden();
	void watched_entity_change();
	void begin_alerting();
	void end_alerting();
	void _schedule_notify();
	void _notify();
	void _notify_done_message();
	void _send_notification_message();
	void async_turn_on();
	void async_turn_off();
	void async_toggle();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif