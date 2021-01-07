#include <integration.h>

integration::integration(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Integration - Riemann sum integral");
	manifest.insert("domain","integration");
}

integration::~integration()
{
}

void integration::init()
{
}


