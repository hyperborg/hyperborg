/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MQTT_JSON_H
#define MQTT_JSON_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mqtt_json : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt_json.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt_json(QObject *parent=nullptr);
    ~mqtt_json();

    QString name() 		{ return "mqtt_json"; }
    QString description()	{ return "The mqtt_json component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif