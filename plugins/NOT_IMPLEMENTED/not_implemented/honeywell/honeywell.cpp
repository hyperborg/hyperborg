#include <honeywell.h>

honeywell::honeywell(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Honeywell Total Connect Comfort (US)");
	manifest.insert("domain","honeywell");
}

honeywell::~honeywell()
{
}

void honeywell::init()
{
}


