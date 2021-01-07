#include <unifiled.h>

unifiled::unifiled(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ubiquiti UniFi LED");
	manifest.insert("domain","unifiled");
}

unifiled::~unifiled()
{
}

void unifiled::init()
{
}


