#include <geo_rss_events.h>

geo_rss_events::geo_rss_events(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GeoRSS");
	manifest.insert("domain","geo_rss_events");
}

geo_rss_events::~geo_rss_events()
{
}

void geo_rss_events::init()
{
}


