#include <caldav.h>

caldav::caldav(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CalDAV");
	manifest.insert("domain","caldav");
}

caldav::~caldav()
{
}

void caldav::init()
{
}


