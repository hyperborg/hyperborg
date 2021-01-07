#include <uvc.h>

uvc::uvc(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ubiquiti UniFi Video");
	manifest.insert("domain","uvc");
}

uvc::~uvc()
{
}

void uvc::init()
{
}


