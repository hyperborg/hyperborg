#include <ness_alarm.h>

ness_alarm::ness_alarm()
{
    	manifest.insert("domain","ness_alarm");
	manifest.insert("name","Ness Alarm");
}

ness_alarm::~ness_alarm()
{
}

void ness_alarm:: async_setup()
{
}


void ness_alarm:: _close()
{
}


void ness_alarm::on_zone_change()
{
}


void ness_alarm::on_state_change()
{
}


void ness_alarm:: handle_panic()
{
}


void ness_alarm:: handle_aux()
{
}


