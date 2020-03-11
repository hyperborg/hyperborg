#include <dublin_bus_transport.h>

dublin_bus_transport::dublin_bus_transport(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Dublin Bus");
	manifest.insert("domain","dublin_bus_transport");
}

dublin_bus_transport::~dublin_bus_transport()
{
}

void dublin_bus_transport::init()
{
}


