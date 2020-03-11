/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MQTT_STATESTREAM_H
#define MQTT_STATESTREAM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mqtt_statestream : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt_statestream.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt_statestream(QObject *parent=nullptr);
    ~mqtt_statestream();

    QString name() 		{ return "mqtt_statestream"; }
    QString description()	{ return "Publish simple item state changes via MQTT."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void _state_publisher();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif