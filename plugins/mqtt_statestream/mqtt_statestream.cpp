#include <mqtt_statestream.h>

mqtt_statestream::mqtt_statestream(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MQTT Statestream");
	manifest.insert("domain","mqtt_statestream");
}

mqtt_statestream::~mqtt_statestream()
{
}

void mqtt_statestream::init()
{
}

void mqtt_statestream::async_setup()
{
}


void mqtt_statestream::_state_publisher()
{
}


