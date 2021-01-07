#include <blinksticklight.h>

blinksticklight::blinksticklight(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","BlinkStick");
	manifest.insert("domain","blinksticklight");
}

blinksticklight::~blinksticklight()
{
}

void blinksticklight::init()
{
}


