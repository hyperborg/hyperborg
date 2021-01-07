#include <opengarage.h>

opengarage::opengarage(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenGarage");
	manifest.insert("domain","opengarage");
}

opengarage::~opengarage()
{
}

void opengarage::init()
{
}


