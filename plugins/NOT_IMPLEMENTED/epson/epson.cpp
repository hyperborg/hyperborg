#include <epson.h>

epson::epson(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Epson");
	manifest.insert("domain","epson");
}

epson::~epson()
{
}

void epson::init()
{
}


