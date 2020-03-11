#include <bitcoin.h>

bitcoin::bitcoin(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bitcoin");
	manifest.insert("domain","bitcoin");
}

bitcoin::~bitcoin()
{
}

void bitcoin::init()
{
}


