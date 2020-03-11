#include <ness_alarm.h>

ness_alarm::ness_alarm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ness Alarm");
	manifest.insert("domain","ness_alarm");
}

ness_alarm::~ness_alarm()
{
}

void ness_alarm::init()
{
}

void ness_alarm::async_setup()
{
}


void ness_alarm::_close()
{
}


void ness_alarm::on_zone_change()
{
}


void ness_alarm::on_state_change()
{
}


void ness_alarm::handle_panic()
{
}


void ness_alarm::handle_aux()
{
}


