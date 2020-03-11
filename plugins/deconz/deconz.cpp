#include <deconz.h>

deconz::deconz(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","deCONZ");
	manifest.insert("domain","deconz");
}

deconz::~deconz()
{
}

void deconz::init()
{
}

void deconz::async_setup()
{
}


void deconz::async_setup_entry()
{
}


void deconz::async_unload_entry()
{
}


void deconz::async_update_master_gateway()
{
}


