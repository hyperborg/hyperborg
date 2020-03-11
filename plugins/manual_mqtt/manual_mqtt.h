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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class manual_mqtt : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "manual_mqtt.json");
    Q_INTERFACES(HyPluginInterface);
public:
    manual_mqtt(QObject *parent=nullptr);
    ~manual_mqtt();

    QString name() 		{ return "manual_mqtt"; }
    QString description()	{ return "The manual_mqtt component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif