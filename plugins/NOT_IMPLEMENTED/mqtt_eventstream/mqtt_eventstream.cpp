#include <mqtt_eventstream.h>

mqtt_eventstream::mqtt_eventstream(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MQTT Eventstream");
	manifest.insert("domain","mqtt_eventstream");
}

mqtt_eventstream::~mqtt_eventstream()
{
}

void mqtt_eventstream::init()
{
}

void mqtt_eventstream::async_setup()
{
}


void mqtt_eventstream::_event_publisher()
{
}


void mqtt_eventstream::_event_receiver()
{
}


