/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WLED_H
#define WLED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class wled : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wled.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wled();
    ~wled();

    QString name() 		{ return "wled"; }
    QString description()	{ return "Support for WLED."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void interval_update();
	void async_unload_entry();
	void __init__();
	void icon();
	void available();
	void entity_registry_enabled_default();
	void should_poll();
	void device_state_attributes();
	void async_added_to_hass();
	void async_will_remove_from_hass();
	void _schedule_immediate_update();
	void async_update();
	void _wled_update();
	void device_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif