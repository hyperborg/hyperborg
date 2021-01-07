#include <totalconnect.h>

totalconnect::totalconnect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Honeywell Total Connect Alarm");
	manifest.insert("domain","totalconnect");
}

totalconnect::~totalconnect()
{
}

void totalconnect::init()
{
}

void totalconnect::setup()
{
}


void totalconnect::__init__()
{
}


