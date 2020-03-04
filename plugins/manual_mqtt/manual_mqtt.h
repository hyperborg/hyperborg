/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MANUAL_MQTT_H
#define MANUAL_MQTT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class manual_mqtt : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "manual_mqtt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    manual_mqtt();
    ~manual_mqtt();

    QString name() 		{ return "manual_mqtt"; }
    QString description()	{ return "The manual_mqtt component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif