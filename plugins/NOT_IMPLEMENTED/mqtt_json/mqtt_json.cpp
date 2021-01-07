#include <mqtt_json.h>

mqtt_json::mqtt_json(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MQTT JSON");
	manifest.insert("domain","mqtt_json");
}

mqtt_json::~mqtt_json()
{
}

void mqtt_json::init()
{
}


