#include <kwb.h>

kwb::kwb(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","KWB Easyfire");
	manifest.insert("domain","kwb");
}

kwb::~kwb()
{
}

void kwb::init()
{
}


