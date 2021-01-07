#include <google_wifi.h>

google_wifi::google_wifi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Wifi");
	manifest.insert("domain","google_wifi");
}

google_wifi::~google_wifi()
{
}

void google_wifi::init()
{
}


