#include <ecoal_boiler.h>

ecoal_boiler::ecoal_boiler(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","eSterownik eCoal.pl Boiler");
	manifest.insert("domain","ecoal_boiler");
}

ecoal_boiler::~ecoal_boiler()
{
}

void ecoal_boiler::init()
{
}

void ecoal_boiler::setup()
{
}


