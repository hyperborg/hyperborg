#include <azure_service_bus.h>

azure_service_bus::azure_service_bus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Azure Service Bus");
	manifest.insert("domain","azure_service_bus");
}

azure_service_bus::~azure_service_bus()
{
}

void azure_service_bus::init()
{
}


