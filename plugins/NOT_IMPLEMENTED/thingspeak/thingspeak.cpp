#include <thingspeak.h>

thingspeak::thingspeak(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ThingSpeak");
	manifest.insert("domain","thingspeak");
}

thingspeak::~thingspeak()
{
}

void thingspeak::init()
{
}

void thingspeak::setup()
{
}


void thingspeak::thingspeak_listener()
{
}


