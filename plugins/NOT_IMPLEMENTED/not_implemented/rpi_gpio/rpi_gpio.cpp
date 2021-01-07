#include <rpi_gpio.h>

rpi_gpio::rpi_gpio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Raspberry Pi GPIO");
	manifest.insert("domain","rpi_gpio");
}

rpi_gpio::~rpi_gpio()
{
}

void rpi_gpio::init()
{
}

void rpi_gpio::setup()
{
}


void rpi_gpio::cleanup_gpio()
{
}


void rpi_gpio::prepare_gpio()
{
}


void rpi_gpio::setup_output()
{
}


void rpi_gpio::setup_input()
{
}


void rpi_gpio::write_output()
{
}


void rpi_gpio::read_input()
{
}


void rpi_gpio::edge_detect()
{
}


