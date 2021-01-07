#include <clickatell.h>

clickatell::clickatell(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Clickatell");
	manifest.insert("domain","clickatell");
}

clickatell::~clickatell()
{
}

void clickatell::init()
{
}


