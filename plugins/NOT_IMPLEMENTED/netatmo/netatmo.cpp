#include <netatmo.h>

netatmo::netatmo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Netatmo");
	manifest.insert("domain","netatmo");
}

netatmo::~netatmo()
{
}

void netatmo::init()
{
}

void netatmo::async_setup()
{
}


void netatmo::async_setup_entry()
{
}


void netatmo::async_unload_entry()
{
}


