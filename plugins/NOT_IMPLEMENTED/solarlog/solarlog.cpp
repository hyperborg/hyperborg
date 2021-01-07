#include <solarlog.h>

solarlog::solarlog(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Solar-Log");
	manifest.insert("domain","solarlog");
}

solarlog::~solarlog()
{
}

void solarlog::init()
{
}

void solarlog::async_setup()
{
}


void solarlog::async_setup_entry()
{
}


void solarlog::async_unload_entry()
{
}


