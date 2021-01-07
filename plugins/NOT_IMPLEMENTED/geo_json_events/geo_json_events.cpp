#include <geo_json_events.h>

geo_json_events::geo_json_events(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GeoJSON");
	manifest.insert("domain","geo_json_events");
}

geo_json_events::~geo_json_events()
{
}

void geo_json_events::init()
{
}


