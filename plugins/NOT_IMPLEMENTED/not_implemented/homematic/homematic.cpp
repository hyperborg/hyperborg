#include <homematic.h>

homematic::homematic(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Homematic");
	manifest.insert("domain","homematic");
}

homematic::~homematic()
{
}

void homematic::init()
{
}

void homematic::setup()
{
}


void homematic::_hm_service_virtualkey()
{
}


void homematic::_service_handle_value()
{
}


void homematic::_service_handle_reconnect()
{
}


void homematic::_service_handle_device()
{
}


void homematic::_service_handle_install_mode()
{
}


void homematic::_service_put_paramset()
{
}


void homematic::_system_callback_handler()
{
}


void homematic::_get_devices()
{
}


void homematic::_create_ha_id()
{
}


void homematic::_hm_event_handler()
{
}


void homematic::_device_from_servicecall()
{
}


