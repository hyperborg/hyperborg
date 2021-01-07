#include <logentries.h>

logentries::logentries(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Logentries");
	manifest.insert("domain","logentries");
}

logentries::~logentries()
{
}

void logentries::init()
{
}

void logentries::setup()
{
}


void logentries::logentries_event_listener()
{
}


