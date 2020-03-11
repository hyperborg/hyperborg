#include <sky_hub.h>

sky_hub::sky_hub(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sky Hub");
	manifest.insert("domain","sky_hub");
}

sky_hub::~sky_hub()
{
}

void sky_hub::init()
{
}


