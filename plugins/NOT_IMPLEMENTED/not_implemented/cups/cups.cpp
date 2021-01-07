#include <cups.h>

cups::cups(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CUPS");
	manifest.insert("domain","cups");
}

cups::~cups()
{
}

void cups::init()
{
}


