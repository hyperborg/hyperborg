#include <tikteck.h>

tikteck::tikteck(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tikteck");
	manifest.insert("domain","tikteck");
}

tikteck::~tikteck()
{
}

void tikteck::init()
{
}


