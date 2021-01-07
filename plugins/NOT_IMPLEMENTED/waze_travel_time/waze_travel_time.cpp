#include <waze_travel_time.h>

waze_travel_time::waze_travel_time(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Waze Travel Time");
	manifest.insert("domain","waze_travel_time");
}

waze_travel_time::~waze_travel_time()
{
}

void waze_travel_time::init()
{
}


