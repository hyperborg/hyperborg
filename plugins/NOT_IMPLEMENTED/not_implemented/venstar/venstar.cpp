#include <venstar.h>

venstar::venstar(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Venstar");
	manifest.insert("domain","venstar");
}

venstar::~venstar()
{
}

void venstar::init()
{
}


