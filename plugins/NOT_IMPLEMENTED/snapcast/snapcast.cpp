#include <snapcast.h>

snapcast::snapcast(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Snapcast");
	manifest.insert("domain","snapcast");
}

snapcast::~snapcast()
{
}

void snapcast::init()
{
}

void snapcast::async_setup()
{
}


void snapcast::service_handle()
{
}


