#include <usgs_earthquakes_feed.h>

usgs_earthquakes_feed::usgs_earthquakes_feed(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","U.S. Geological Survey Earthquake Hazards (USGS)");
	manifest.insert("domain","usgs_earthquakes_feed");
}

usgs_earthquakes_feed::~usgs_earthquakes_feed()
{
}

void usgs_earthquakes_feed::init()
{
}


