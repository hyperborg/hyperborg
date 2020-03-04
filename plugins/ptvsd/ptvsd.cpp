#include <ptvsd.h>

ptvsd::ptvsd()
{
    	manifest.insert("domain","ptvsd");
	manifest.insert("name","PTVSD - Python Tools for Visual Studio Debug Server");
}

ptvsd::~ptvsd()
{
}

void ptvsd:: async_setup()
{
}


void ptvsd::waitfor()
{
}


