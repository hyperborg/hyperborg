#include <duckdns.h>

duckdns::duckdns(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Duck DNS");
	manifest.insert("domain","duckdns");
}

duckdns::~duckdns()
{
}

void duckdns::init()
{
}

void duckdns::async_setup()
{
}


void duckdns::update_domain_interval()
{
}


void duckdns::update_domain_service()
{
}


void duckdns::_update_duckdns()
{
}


void duckdns::async_track_time_interval_backoff()
{
}


void duckdns::interval_listener()
{
}


void duckdns::remove_listener()
{
}


