/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MQTT_EVENTSTREAM_H
#define MQTT_EVENTSTREAM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class mqtt_eventstream : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt_eventstream.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt_eventstream();
    ~mqtt_eventstream();

    QString name() 		{ return "mqtt_eventstream"; }
    QString description()	{ return "Connect two Home Assistant instances via MQTT."; }

protected:
    	void async_setup();
	void _event_publisher();
	void _event_receiver();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif