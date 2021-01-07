#include <lightwave.h>

lightwave::lightwave(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Lightwave");
	manifest.insert("domain","lightwave");
}

lightwave::~lightwave()
{
}

void lightwave::init()
{
}

void lightwave::async_setup()
{
}


