#include <arduino.h>

arduino::arduino(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Arduino");
	manifest.insert("domain","arduino");
}

arduino::~arduino()
{
}

void arduino::init()
{
}

void arduino::setup()
{
}


void arduino::stop_arduino()
{
}


void arduino::start_arduino()
{
}


void arduino::__init__()
{
}


void arduino::set_mode()
{
}


void arduino::get_analog_inputs()
{
}


void arduino::set_digital_out_high()
{
}


void arduino::set_digital_out_low()
{
}


void arduino::get_digital_in()
{
}


void arduino::get_analog_in()
{
}


void arduino::get_firmata()
{
}


void arduino::disconnect()
{
}


