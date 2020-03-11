#include <bh1750.h>

bh1750::bh1750(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","BH1750");
	manifest.insert("domain","bh1750");
}

bh1750::~bh1750()
{
}

void bh1750::init()
{
}


