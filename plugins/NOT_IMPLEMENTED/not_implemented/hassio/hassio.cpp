#include <hassio.h>

hassio::hassio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Hass.io");
	manifest.insert("domain","hassio");
}

hassio::~hassio()
{
}

void hassio::init()
{
}

void hassio::get_homeassistant_version()
{
}


void hassio::is_hassio()
{
}


void hassio::async_setup()
{
}


void hassio::push_config()
{
}


void hassio::async_service_handler()
{
}


void hassio::update_homeassistant_version()
{
}


void hassio::async_handle_core_service()
{
}


