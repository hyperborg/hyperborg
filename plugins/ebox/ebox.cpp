#include <ebox.h>

ebox::ebox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","EBox");
	manifest.insert("domain","ebox");
}

ebox::~ebox()
{
}

void ebox::init()
{
}


