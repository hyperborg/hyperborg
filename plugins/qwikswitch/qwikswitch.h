/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef QWIKSWITCH_H
#define QWIKSWITCH_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class qwikswitch : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qwikswitch.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qwikswitch();
    ~qwikswitch();

    QString name() 		{ return "qwikswitch"; }
    QString description()	{ return "Support for Qwikswitch devices."; }

protected:
    	void __init__();
	void name();
	void poll();
	void unique_id();
	void update_packet();
	void  async_added_to_hass();
	void __init__();
	void is_on();
	void  async_turn_on();
	void  async_turn_off();
	void  async_setup();
	void callback_value_changed();
	void callback_qs_listen();
	void async_start();
	void async_stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif