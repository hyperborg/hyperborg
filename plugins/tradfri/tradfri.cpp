#include <tradfri.h>

tradfri::tradfri(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IKEA TRÅDFRI (TRADFRI)");
	manifest.insert("domain","tradfri");
}

tradfri::~tradfri()
{
}

void tradfri::init()
{
}

void tradfri::async_setup()
{
}


void tradfri::async_setup_entry()
{
}


void tradfri::on_hass_stop()
{
}


