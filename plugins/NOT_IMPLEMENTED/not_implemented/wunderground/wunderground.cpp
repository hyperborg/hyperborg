#include <wunderground.h>

wunderground::wunderground(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Weather Underground (WUnderground)");
	manifest.insert("domain","wunderground");
}

wunderground::~wunderground()
{
}

void wunderground::init()
{
}


