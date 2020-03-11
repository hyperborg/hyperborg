#include <opensky.h>

opensky::opensky(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenSky Network");
	manifest.insert("domain","opensky");
}

opensky::~opensky()
{
}

void opensky::init()
{
}


