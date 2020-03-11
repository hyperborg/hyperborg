#include <kodi.h>

kodi::kodi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Kodi");
	manifest.insert("domain","kodi");
}

kodi::~kodi()
{
}

void kodi::init()
{
}

void kodi::async_setup()
{
}


void kodi::async_service_handler()
{
}


