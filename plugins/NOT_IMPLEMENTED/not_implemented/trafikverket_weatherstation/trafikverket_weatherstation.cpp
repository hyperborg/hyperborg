#include <trafikverket_weatherstation.h>

trafikverket_weatherstation::trafikverket_weatherstation(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Trafikverket Weather Station");
	manifest.insert("domain","trafikverket_weatherstation");
}

trafikverket_weatherstation::~trafikverket_weatherstation()
{
}

void trafikverket_weatherstation::init()
{
}


