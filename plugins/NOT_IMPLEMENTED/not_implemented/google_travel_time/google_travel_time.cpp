#include <google_travel_time.h>

google_travel_time::google_travel_time(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Maps Travel Time");
	manifest.insert("domain","google_travel_time");
}

google_travel_time::~google_travel_time()
{
}

void google_travel_time::init()
{
}


