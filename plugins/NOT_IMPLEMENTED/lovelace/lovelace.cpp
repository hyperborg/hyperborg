#include <lovelace.h>

lovelace::lovelace(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Lovelace");
	manifest.insert("domain","lovelace");
}

lovelace::~lovelace()
{
}

void lovelace::init()
{
}

void lovelace::async_setup()
{
}


void lovelace::storage_dashboard_changed()
{
}


void lovelace::system_health_info()
{
}


void lovelace::_register_panel()
{
}


