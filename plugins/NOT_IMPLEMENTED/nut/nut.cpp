#include <nut.h>

nut::nut(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Network UPS Tools (NUT)");
	manifest.insert("domain","nut");
}

nut::~nut()
{
}

void nut::init()
{
}


