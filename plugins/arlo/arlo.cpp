#include <arlo.h>

arlo::arlo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Arlo");
	manifest.insert("domain","arlo");
}

arlo::~arlo()
{
}

void arlo::init()
{
}

void arlo::setup()
{
}


void arlo::hub_refresh()
{
}


