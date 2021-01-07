#include <flic.h>

flic::flic(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Flic");
	manifest.insert("domain","flic");
}

flic::~flic()
{
}

void flic::init()
{
}


