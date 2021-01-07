#include <hyperion.h>

hyperion::hyperion(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Hyperion");
	manifest.insert("domain","hyperion");
}

hyperion::~hyperion()
{
}

void hyperion::init()
{
}


