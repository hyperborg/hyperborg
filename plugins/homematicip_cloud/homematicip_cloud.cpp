#include <homematicip_cloud.h>

homematicip_cloud::homematicip_cloud(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HomematicIP Cloud");
	manifest.insert("domain","homematicip_cloud");
}

homematicip_cloud::~homematicip_cloud()
{
}

void homematicip_cloud::init()
{
}

void homematicip_cloud::async_setup()
{
}


void homematicip_cloud::async_setup_entry()
{
}


void homematicip_cloud::async_unload_entry()
{
}


