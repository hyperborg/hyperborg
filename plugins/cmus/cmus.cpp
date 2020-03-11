#include <cmus.h>

cmus::cmus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","cmus");
	manifest.insert("domain","cmus");
}

cmus::~cmus()
{
}

void cmus::init()
{
}


