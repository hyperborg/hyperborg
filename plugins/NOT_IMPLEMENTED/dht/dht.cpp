#include <dht.h>

dht::dht(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DHT Sensor");
	manifest.insert("domain","dht");
}

dht::~dht()
{
}

void dht::init()
{
}


