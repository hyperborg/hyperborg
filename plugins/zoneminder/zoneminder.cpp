#include <zoneminder.h>

zoneminder::zoneminder(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ZoneMinder");
	manifest.insert("domain","zoneminder");
}

zoneminder::~zoneminder()
{
}

void zoneminder::init()
{
}

void zoneminder::setup()
{
}


void zoneminder::set_active_state()
{
}


