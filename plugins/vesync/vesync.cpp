#include <vesync.h>

vesync::vesync(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Etekcity VeSync");
	manifest.insert("domain","vesync");
}

vesync::~vesync()
{
}

void vesync::init()
{
}

void vesync::async_setup()
{
}


void vesync::async_setup_entry()
{
}


void vesync::async_new_device_discovery()
{
}


void vesync::async_unload_entry()
{
}


