#include <mobile_app.h>

mobile_app::mobile_app(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Home Assistant Mobile App Support");
	manifest.insert("domain","mobile_app");
}

mobile_app::~mobile_app()
{
}

void mobile_app::init()
{
}

void mobile_app::async_setup()
{
}


void mobile_app::async_setup_entry()
{
}


void mobile_app::async_unload_entry()
{
}


void mobile_app::async_remove_entry()
{
}


