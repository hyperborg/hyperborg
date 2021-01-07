#include <linky.h>

linky::linky(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Enedis Linky");
	manifest.insert("domain","linky");
}

linky::~linky()
{
}

void linky::init()
{
}

void linky::async_setup()
{
}


void linky::async_setup_entry()
{
}


void linky::async_unload_entry()
{
}


