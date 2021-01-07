#include <tibber.h>

tibber::tibber(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tibber");
	manifest.insert("domain","tibber");
}

tibber::~tibber()
{
}

void tibber::init()
{
}

void tibber::async_setup()
{
}


void tibber::_close()
{
}


