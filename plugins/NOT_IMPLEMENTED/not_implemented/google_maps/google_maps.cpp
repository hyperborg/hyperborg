#include <google_maps.h>

google_maps::google_maps(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Maps");
	manifest.insert("domain","google_maps");
}

google_maps::~google_maps()
{
}

void google_maps::init()
{
}


