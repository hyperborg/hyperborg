#include <noaa_tides.h>

noaa_tides::noaa_tides(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","NOAA Tides");
	manifest.insert("domain","noaa_tides");
}

noaa_tides::~noaa_tides()
{
}

void noaa_tides::init()
{
}


