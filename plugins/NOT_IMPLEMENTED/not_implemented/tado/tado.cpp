#include <tado.h>

tado::tado(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tado");
	manifest.insert("domain","tado");
}

tado::~tado()
{
}

void tado::init()
{
}

void tado::setup()
{
}


void tado::__init__()
{
}


void tado::fallback()
{
}


void tado::update()
{
}


void tado::update_sensor()
{
}


void tado::get_capabilities()
{
}


void tado::reset_zone_overlay()
{
}


void tado::set_zone_overlay()
{
}


void tado::set_zone_off()
{
}


