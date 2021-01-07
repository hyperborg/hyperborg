#include <azure_event_hub.h>

azure_event_hub::azure_event_hub(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Azure Event Hub");
	manifest.insert("domain","azure_event_hub");
}

azure_event_hub::~azure_event_hub()
{
}

void azure_event_hub::init()
{
}

void azure_event_hub::async_setup()
{
}


void azure_event_hub::async_send_to_event_hub()
{
}


void azure_event_hub::async_shutdown()
{
}


