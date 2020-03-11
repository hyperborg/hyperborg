#include <device_sun_light_trigger.h>

device_sun_light_trigger::device_sun_light_trigger(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Presence-based Lights");
	manifest.insert("domain","device_sun_light_trigger");
}

device_sun_light_trigger::~device_sun_light_trigger()
{
}

void device_sun_light_trigger::init()
{
}

void device_sun_light_trigger::async_setup()
{
}


void device_sun_light_trigger::anyone_home()
{
}


void device_sun_light_trigger::any_light_on()
{
}


void device_sun_light_trigger::calc_time_for_light_when_sunset()
{
}


void device_sun_light_trigger::async_turn_on_before_sunset()
{
}


void device_sun_light_trigger::async_turn_on_factory()
{
}


void device_sun_light_trigger::async_turn_on_light()
{
}


void device_sun_light_trigger::schedule_light_turn_on()
{
}


void device_sun_light_trigger::check_light_on_dev_state_change()
{
}


void device_sun_light_trigger::turn_off_lights_when_all_leave()
{
}


