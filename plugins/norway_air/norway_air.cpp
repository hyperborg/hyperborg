#include <norway_air.h>

norway_air::norway_air(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Om Luftkvalitet i Norge (Norway Air)");
	manifest.insert("domain","norway_air");
}

norway_air::~norway_air()
{
}

void norway_air::init()
{
}


