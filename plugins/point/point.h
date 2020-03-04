/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef POINT_H
#define POINT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class point : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "point.json");
    Q_INTERFACES(HyPluginInterface);
public:
    point();
    ~point();

    QString name() 		{ return "point"; }
    QString description()	{ return "Support for Minut Point."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void token_saver();
	void  async_setup_webhook();
	void  async_unload_entry();
	void  handle_webhook();
	void __init__();
	void  update();
	void  _sync();
	void  new_device();
	void device();
	void is_available();
	void remove_webhook();
	void homes();
	void alarm_disarm();
	void alarm_arm();
	void __init__();
	void __str__();
	void  async_added_to_hass();
	void  async_will_remove_from_hass();
	void  _update_callback();
	void available();
	void device();
	void device_class();
	void device_id();
	void device_state_attributes();
	void device_info();
	void name();
	void is_updated();
	void last_update();
	void should_poll();
	void unique_id();
	void value();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif