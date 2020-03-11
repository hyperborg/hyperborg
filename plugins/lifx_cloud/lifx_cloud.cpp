#include <lifx_cloud.h>

lifx_cloud::lifx_cloud(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LIFX Cloud");
	manifest.insert("domain","lifx_cloud");
}

lifx_cloud::~lifx_cloud()
{
}

void lifx_cloud::init()
{
}


