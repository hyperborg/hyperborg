#include <gntp.h>

gntp::gntp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Growl (GnGNTP)");
	manifest.insert("domain","gntp");
}

gntp::~gntp()
{
}

void gntp::init()
{
}


