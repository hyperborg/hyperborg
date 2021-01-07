#include <automatic.h>

automatic::automatic(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Automatic");
	manifest.insert("domain","automatic");
}

automatic::~automatic()
{
}

void automatic::init()
{
}


