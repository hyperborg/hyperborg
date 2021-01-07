#include <plaato.h>

plaato::plaato(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Plaato Airlock");
	manifest.insert("domain","plaato");
}

plaato::~plaato()
{
}

void plaato::init()
{
}

void plaato::async_setup()
{
}


void plaato::async_setup_entry()
{
}


void plaato::async_unload_entry()
{
}


void plaato::handle_webhook()
{
}


void plaato::_device_id()
{
}


