#include <zeroconf.h>

zeroconf::zeroconf(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Zero-configuration networking (zeroconf)");
	manifest.insert("domain","zeroconf");
}

zeroconf::~zeroconf()
{
}

void zeroconf::init()
{
}

void zeroconf::setup()
{
}


void zeroconf::zeroconf_hass_start()
{
}


void zeroconf::service_update()
{
}


void zeroconf::stop_zeroconf()
{
}


void zeroconf::handle_homekit()
{
}


void zeroconf::info_from_service()
{
}


