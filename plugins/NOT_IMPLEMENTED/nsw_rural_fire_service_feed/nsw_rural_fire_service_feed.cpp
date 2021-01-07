#include <nsw_rural_fire_service_feed.h>

nsw_rural_fire_service_feed::nsw_rural_fire_service_feed(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NSW Rural Fire Service Incidents");
	manifest.insert("domain","nsw_rural_fire_service_feed");
}

nsw_rural_fire_service_feed::~nsw_rural_fire_service_feed()
{
}

void nsw_rural_fire_service_feed::init()
{
}


