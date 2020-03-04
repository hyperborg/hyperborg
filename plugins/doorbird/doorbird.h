/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DOORBIRD_H
#define DOORBIRD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class doorbird : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "doorbird.json");
    Q_INTERFACES(HyPluginInterface);
public:
    doorbird();
    ~doorbird();

    QString name() 		{ return "doorbird"; }
    QString description()	{ return "Support for DoorBird devices."; }

protected:
    	void setup();
	void _reset_device_favorites_handler();
	void get_doorstation_by_token();
	void __init__();
	void device();
	void custom_url();
	void token();
	void register_events();
	void slug();
	void _get_event_name();
	void _register_event();
	void webhook_is_registered();
	void get_webhook_id();
	void get_event_data();
	void  get();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif