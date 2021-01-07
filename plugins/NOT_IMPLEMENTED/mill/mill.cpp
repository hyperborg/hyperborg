#include <mill.h>

mill::mill(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mill");
	manifest.insert("domain","mill");
}

mill::~mill()
{
}

void mill::init()
{
}


