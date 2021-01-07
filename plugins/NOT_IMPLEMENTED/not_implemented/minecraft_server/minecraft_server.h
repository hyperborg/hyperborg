/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MINECRAFT_SERVER_H
#define MINECRAFT_SERVER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class minecraft_server : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "minecraft_server.json");
    Q_INTERFACES(HyPluginInterface);
public:
    minecraft_server(QObject *parent=nullptr);
    ~minecraft_server();

    QString name() 		{ return "minecraft_server"; }
    QString description()	{ return "The Minecraft Server integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void start_periodic_update();
	void stop_periodic_update();
	void async_check_connection();
	void async_update();
	void _async_status_request();
	void unique_id();
	void device_info();
	void device_class();
	void icon();
	void should_poll();
	void async_added_to_hass();
	void async_will_remove_from_hass();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif