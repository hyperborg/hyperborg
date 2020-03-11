#include <squeezebox.h>

squeezebox::squeezebox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Logitech Squeezebox");
	manifest.insert("domain","squeezebox");
}

squeezebox::~squeezebox()
{
}

void squeezebox::init()
{
}


