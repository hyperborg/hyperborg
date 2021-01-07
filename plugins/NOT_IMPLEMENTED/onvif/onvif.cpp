#include <onvif.h>

onvif::onvif(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ONVIF");
	manifest.insert("domain","onvif");
}

onvif::~onvif()
{
}

void onvif::init()
{
}


