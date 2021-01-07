#include <orangepi_gpio.h>

orangepi_gpio::orangepi_gpio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Orangepi GPIO");
	manifest.insert("domain","orangepi_gpio");
}

orangepi_gpio::~orangepi_gpio()
{
}

void orangepi_gpio::init()
{
}

void orangepi_gpio::async_setup()
{
}


void orangepi_gpio::cleanup_gpio()
{
}


void orangepi_gpio::prepare_gpio()
{
}


void orangepi_gpio::setup_mode()
{
}


void orangepi_gpio::setup_input()
{
}


void orangepi_gpio::read_input()
{
}


void orangepi_gpio::edge_detect()
{
}


