#include <nws.h>

nws::nws(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","National Weather Service (NWS)");
	manifest.insert("domain","nws");
}

nws::~nws()
{
}

void nws::init()
{
}


