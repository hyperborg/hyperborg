#include <flexit.h>

flexit::flexit(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Flexit");
	manifest.insert("domain","flexit");
}

flexit::~flexit()
{
}

void flexit::init()
{
}


