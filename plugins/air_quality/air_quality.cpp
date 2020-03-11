#include <air_quality.h>

air_quality::air_quality(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Air Quality");
	manifest.insert("domain","air_quality");
}

air_quality::~air_quality()
{
}

void air_quality::init()
{
}

void air_quality::async_setup()
{
}


void air_quality::async_setup_entry()
{
}


void air_quality::async_unload_entry()
{
}


void air_quality::particulate_matter_2_5()
{
}


void air_quality::particulate_matter_10()
{
}


void air_quality::particulate_matter_0_1()
{
}


void air_quality::air_quality_index()
{
}


void air_quality::ozone()
{
}


void air_quality::carbon_monoxide()
{
}


void air_quality::carbon_dioxide()
{
}


void air_quality::attribution()
{
}


void air_quality::sulphur_dioxide()
{
}


void air_quality::nitrogen_oxide()
{
}


void air_quality::nitrogen_monoxide()
{
}


void air_quality::nitrogen_dioxide()
{
}


void air_quality::state_attributes()
{
}


void air_quality::state()
{
}


