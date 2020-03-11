#include <upnp.h>

upnp::upnp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","UPnP");
	manifest.insert("domain","upnp");
}

upnp::~upnp()
{
}

void upnp::init()
{
}

void upnp::_substitute_hass_ports()
{
}


void upnp::async_discover_and_construct()
{
}


void upnp::async_setup()
{
}


void upnp::async_setup_entry()
{
}


void upnp::delete_port_mapping()
{
}


void upnp::async_unload_entry()
{
}


