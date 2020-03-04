/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WIRELESSTAG_H
#define WIRELESSTAG_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class wirelesstag : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "wirelesstag.json");
    Q_INTERFACES(HyPluginInterface);
public:
    wirelesstag();
    ~wirelesstag();

    QString name() 		{ return "wirelesstag"; }
    QString description()	{ return "Support for Wireless Sensor Tags."; }

protected:
    	void __init__();
	void tag_manager_macs();
	void load_tags();
	void arm();
	void disarm();
	void make_notifications();
	void install_push_notifications();
	void local_base_url();
	void update_callback_url();
	void binary_event_callback_url();
	void handle_update_tags_event();
	void handle_binary_event();
	void setup();
	void should_poll();
	void principal_value();
	void updated_state_value();
	void decorate_value();
	void available();
	void update();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif