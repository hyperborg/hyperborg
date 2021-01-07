#include <ephember.h>

ephember::ephember(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","EPH Controls");
	manifest.insert("domain","ephember");
}

ephember::~ephember()
{
}

void ephember::init()
{
}


