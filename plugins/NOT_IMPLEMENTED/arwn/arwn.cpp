#include <arwn.h>

arwn::arwn(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ambient Radio Weather Network");
	manifest.insert("domain","arwn");
}

arwn::~arwn()
{
}

void arwn::init()
{
}


