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

class mqtt_statestream : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt_statestream.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt_statestream();
    ~mqtt_statestream();

    QString name() 		{ return "mqtt_statestream"; }
    QString description()	{ return "Publish simple item state changes via MQTT."; }

protected:
    	void  async_setup();
	void _state_publisher();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif