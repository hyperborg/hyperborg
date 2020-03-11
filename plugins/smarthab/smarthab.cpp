#include <smarthab.h>

smarthab::smarthab(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SmartHab");
	manifest.insert("domain","smarthab");
}

smarthab::~smarthab()
{
}

void smarthab::init()
{
}

void smarthab::setup()
{
}


