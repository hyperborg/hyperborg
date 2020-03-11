#include <ptvsd.h>

ptvsd::ptvsd(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","PTVSD - Python Tools for Visual Studio Debug Server");
	manifest.insert("domain","ptvsd");
}

ptvsd::~ptvsd()
{
}

void ptvsd::init()
{
}

void ptvsd::async_setup()
{
}


void ptvsd::waitfor()
{
}


