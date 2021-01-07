#include <withings.h>

withings::withings(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Withings");
	manifest.insert("domain","withings");
}

withings::~withings()
{
}

void withings::init()
{
}

void withings::async_setup()
{
}


void withings::async_setup_entry()
{
}


void withings::async_unload_entry()
{
}


