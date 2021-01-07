#include <thethingsnetwork.h>

thethingsnetwork::thethingsnetwork(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","The Things Network");
	manifest.insert("domain","thethingsnetwork");
}

thethingsnetwork::~thethingsnetwork()
{
}

void thethingsnetwork::init()
{
}

void thethingsnetwork::async_setup()
{
}


