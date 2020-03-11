#include <utility_meter.h>

utility_meter::utility_meter(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Utility Meter");
	manifest.insert("domain","utility_meter");
}

utility_meter::~utility_meter()
{
}

void utility_meter::init()
{
}

void utility_meter::async_setup()
{
}


void utility_meter::__init__()
{
}


void utility_meter::async_added_to_hass()
{
}


void utility_meter::should_poll()
{
}


void utility_meter::icon()
{
}


void utility_meter::state()
{
}


void utility_meter::state_attributes()
{
}


void utility_meter::async_reset_meters()
{
}


void utility_meter::async_select_tariff()
{
}


void utility_meter::async_next_tariff()
{
}


