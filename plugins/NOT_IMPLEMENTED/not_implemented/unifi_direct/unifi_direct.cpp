#include <unifi_direct.h>

unifi_direct::unifi_direct(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ubiquiti UniFi AP");
	manifest.insert("domain","unifi_direct");
}

unifi_direct::~unifi_direct()
{
}

void unifi_direct::init()
{
}


