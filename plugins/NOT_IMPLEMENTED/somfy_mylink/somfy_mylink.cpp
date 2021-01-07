#include <somfy_mylink.h>

somfy_mylink::somfy_mylink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Somfy MyLink");
	manifest.insert("domain","somfy_mylink");
}

somfy_mylink::~somfy_mylink()
{
}

void somfy_mylink::init()
{
}

void somfy_mylink::validate_entity_config()
{
}


void somfy_mylink::async_setup()
{
}


