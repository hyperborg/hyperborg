/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AMBIENT_STATION_H
#define AMBIENT_STATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ambient_station : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ambient_station.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ambient_station(QObject *parent=nullptr);
    ~ambient_station();

    QString name() 		{ return "ambient_station"; }
    QString description()	{ return "Support for Ambient Weather Station Service."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void async_migrate_entry();
	void __init__();
	void _attempt_connect();
	void ws_connect();
	void _ws_reconnect();
	void on_connect();
	void on_data();
	void on_disconnect();
	void on_subscribed();
	void ws_disconnect();
	void available();
	void device_class();
	void device_info();
	void should_poll();
	void unique_id();
	void async_added_to_hass();
	void update();
	void async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif