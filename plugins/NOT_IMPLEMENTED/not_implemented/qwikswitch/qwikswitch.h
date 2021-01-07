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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class qwikswitch : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "qwikswitch.json");
    Q_INTERFACES(HyPluginInterface);
public:
    qwikswitch(QObject *parent=nullptr);
    ~qwikswitch();

    QString name() 		{ return "qwikswitch"; }
    QString description()	{ return "Support for Qwikswitch devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void __init__();
	void poll();
	void unique_id();
	void update_packet();
	void async_added_to_hass();
	void is_on();
	void async_turn_on();
	void async_turn_off();
	void async_setup();
	void callback_value_changed();
	void callback_qs_listen();
	void async_start();
	void async_stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif