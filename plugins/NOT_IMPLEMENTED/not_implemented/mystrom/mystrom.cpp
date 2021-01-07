#include <mystrom.h>

mystrom::mystrom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","myStrom");
	manifest.insert("domain","mystrom");
}

mystrom::~mystrom()
{
}

void mystrom::init()
{
}


