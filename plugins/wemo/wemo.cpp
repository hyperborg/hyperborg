#include <wemo.h>

wemo::wemo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Belkin WeMo");
	manifest.insert("domain","wemo");
}

wemo::~wemo()
{
}

void wemo::init()
{
}

void wemo::coerce_host_port()
{
}


void wemo::async_setup()
{
}


void wemo::async_setup_entry()
{
}


void wemo::stop_wemo()
{
}


void wemo::validate_static_config()
{
}


void wemo::setup_url_for_address()
{
}


