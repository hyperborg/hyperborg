#include <zha.h>

zha::zha(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Zigbee Home Automation");
	manifest.insert("domain","zha");
}

zha::~zha()
{
}

void zha::init()
{
}

void zha::async_setup()
{
}


void zha::async_setup_entry()
{
}


void zha::_platforms_loaded()
{
}


void zha::async_zha_shutdown()
{
}


void zha::async_unload_entry()
{
}


