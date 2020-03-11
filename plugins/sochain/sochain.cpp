#include <sochain.h>

sochain::sochain(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SoChain");
	manifest.insert("domain","sochain");
}

sochain::~sochain()
{
}

void sochain::init()
{
}


