#include <lyft.h>

lyft::lyft(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Lyft");
	manifest.insert("domain","lyft");
}

lyft::~lyft()
{
}

void lyft::init()
{
}


