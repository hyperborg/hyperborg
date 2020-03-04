#include <bbb_gpio.h>

bbb_gpio::bbb_gpio()
{
    	manifest.insert("name","BeagleBone Black GPIO");
	manifest.insert("domain","bbb_gpio");
}

bbb_gpio::~bbb_gpio()
{
}

void bbb_gpio::setup()
{
}


void bbb_gpio::cleanup_gpio()
{
}


void bbb_gpio::prepare_gpio()
{
}


void bbb_gpio::setup_output()
{
}


void bbb_gpio::setup_input()
{
}


void bbb_gpio::write_output()
{
}


void bbb_gpio::read_input()
{
}


void bbb_gpio::edge_detect()
{
}


