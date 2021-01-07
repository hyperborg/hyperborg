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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mqtt_eventstream : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt_eventstream.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt_eventstream(QObject *parent=nullptr);
    ~mqtt_eventstream();

    QString name() 		{ return "mqtt_eventstream"; }
    QString description()	{ return "Connect two Home Assistant instances via MQTT."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void _event_publisher();
	void _event_receiver();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif