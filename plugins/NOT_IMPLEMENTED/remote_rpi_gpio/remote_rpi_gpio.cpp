#include <remote_rpi_gpio.h>

remote_rpi_gpio::remote_rpi_gpio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","remote_rpi_gpio");
	manifest.insert("domain","remote_rpi_gpio");
}

remote_rpi_gpio::~remote_rpi_gpio()
{
}

void remote_rpi_gpio::init()
{
}

void remote_rpi_gpio::setup()
{
}


void remote_rpi_gpio::setup_output()
{
}


void remote_rpi_gpio::setup_input()
{
}


void remote_rpi_gpio::write_output()
{
}


void remote_rpi_gpio::read_input()
{
}


