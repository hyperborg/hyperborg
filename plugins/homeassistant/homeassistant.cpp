#include <homeassistant.h>

homeassistant::homeassistant()
{
    	manifest.insert("name","Home Assistant Core Integration");
	manifest.insert("domain","homeassistant");
}

homeassistant::~homeassistant()
{
}

void homeassistant:: async_setup()
{
}


void homeassistant:: async_handle_turn_service()
{
}


void homeassistant:: async_handle_core_service()
{
}


void homeassistant:: async_handle_update_service()
{
}


void homeassistant:: async_handle_reload_config()
{
}


void homeassistant:: async_set_location()
{
}


