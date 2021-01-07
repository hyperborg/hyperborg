#include <mikrotik.h>

mikrotik::mikrotik(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mikrotik");
	manifest.insert("domain","mikrotik");
}

mikrotik::~mikrotik()
{
}

void mikrotik::init()
{
}

void mikrotik::async_setup()
{
}


void mikrotik::async_setup_entry()
{
}


void mikrotik::async_unload_entry()
{
}


