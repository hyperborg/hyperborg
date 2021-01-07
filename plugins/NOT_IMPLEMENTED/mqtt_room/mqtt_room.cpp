#include <mqtt_room.h>

mqtt_room::mqtt_room(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MQTT Room Presence");
	manifest.insert("domain","mqtt_room");
}

mqtt_room::~mqtt_room()
{
}

void mqtt_room::init()
{
}


