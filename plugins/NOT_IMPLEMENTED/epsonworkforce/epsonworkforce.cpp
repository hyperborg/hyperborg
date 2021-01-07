#include <epsonworkforce.h>

epsonworkforce::epsonworkforce(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Epson Workforce");
	manifest.insert("domain","epsonworkforce");
}

epsonworkforce::~epsonworkforce()
{
}

void epsonworkforce::init()
{
}


