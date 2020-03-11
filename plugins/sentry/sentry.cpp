#include <sentry.h>

sentry::sentry(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sentry");
	manifest.insert("domain","sentry");
}

sentry::~sentry()
{
}

void sentry::init()
{
}

void sentry::async_setup()
{
}


void sentry::async_setup_entry()
{
}


