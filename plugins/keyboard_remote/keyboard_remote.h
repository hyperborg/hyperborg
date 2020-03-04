/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KEYBOARD_REMOTE_H
#define KEYBOARD_REMOTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class keyboard_remote : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "keyboard_remote.json");
    Q_INTERFACES(HyPluginInterface);
public:
    keyboard_remote();
    ~keyboard_remote();

    QString name() 		{ return "keyboard_remote"; }
    QString description()	{ return "Receive signals from a keyboard and use it as a remote control."; }

protected:
    	void async_setup();
	void __init__();
	void setup();
	void async_start_monitoring();
	void async_stop_monitoring();
	void get_device_handler();
	void async_monitor_devices();
	void async_keyrepeat();
	void async_monitor_input();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif