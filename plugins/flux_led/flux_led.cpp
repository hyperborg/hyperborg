#include <flux_led.h>

flux_led::flux_led(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Flux LED/MagicLight");
	manifest.insert("domain","flux_led");
}

flux_led::~flux_led()
{
}

void flux_led::init()
{
}


