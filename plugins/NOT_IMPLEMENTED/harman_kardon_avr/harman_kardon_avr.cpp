#include <harman_kardon_avr.h>

harman_kardon_avr::harman_kardon_avr(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Harman Kardon AVR");
	manifest.insert("domain","harman_kardon_avr");
}

harman_kardon_avr::~harman_kardon_avr()
{
}

void harman_kardon_avr::init()
{
}


