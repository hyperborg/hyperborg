#include <github.h>

github::github(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","GitHub");
	manifest.insert("domain","github");
}

github::~github()
{
}

void github::init()
{
}


