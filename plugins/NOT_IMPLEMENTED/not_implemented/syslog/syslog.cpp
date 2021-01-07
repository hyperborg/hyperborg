#include <syslog.h>

syslog::syslog(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Syslog");
	manifest.insert("domain","syslog");
}

syslog::~syslog()
{
}

void syslog::init()
{
}


