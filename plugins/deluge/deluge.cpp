#include <deluge.h>

deluge::deluge(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Deluge");
	manifest.insert("domain","deluge");
}

deluge::~deluge()
{
}

void deluge::init()
{
}


