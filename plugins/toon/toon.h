/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TOON_H
#define TOON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class toon : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "toon.json");
    Q_INTERFACES(HyPluginInterface);
public:
    toon();
    ~toon();

    QString name() 		{ return "toon"; }
    QString description()	{ return "Support for Toon van Eneco devices."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void update();
	void __init__();
	void display_name();
	void icon();
	void should_poll();
	void  async_added_to_hass();
	void  async_will_remove_from_hass();
	void _schedule_immediate_update();
	void device_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif