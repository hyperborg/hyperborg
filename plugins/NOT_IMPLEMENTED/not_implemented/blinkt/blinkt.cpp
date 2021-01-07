#include <blinkt.h>

blinkt::blinkt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Blinkt!");
	manifest.insert("domain","blinkt");
}

blinkt::~blinkt()
{
}

void blinkt::init()
{
}


