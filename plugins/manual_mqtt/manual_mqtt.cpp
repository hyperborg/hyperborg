#include <manual_mqtt.h>

manual_mqtt::manual_mqtt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Manual MQTT");
	manifest.insert("domain","manual_mqtt");
}

manual_mqtt::~manual_mqtt()
{
}

void manual_mqtt::init()
{
}


