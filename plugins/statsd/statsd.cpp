#include <statsd.h>

statsd::statsd(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","StatsD");
	manifest.insert("domain","statsd");
}

statsd::~statsd()
{
}

void statsd::init()
{
}

void statsd::setup()
{
}


void statsd::statsd_event_listener()
{
}


