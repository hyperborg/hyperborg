#include <avion.h>

avion::avion(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Avi-on");
	manifest.insert("domain","avion");
}

avion::~avion()
{
}

void avion::init()
{
}


