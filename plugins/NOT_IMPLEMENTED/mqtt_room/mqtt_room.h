/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MQTT_ROOM_H
#define MQTT_ROOM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class mqtt_room : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "mqtt_room.json");
    Q_INTERFACES(HyPluginInterface);
public:
    mqtt_room(QObject *parent=nullptr);
    ~mqtt_room();

    QString name() 		{ return "mqtt_room"; }
    QString description()	{ return "The mqtt_room component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif