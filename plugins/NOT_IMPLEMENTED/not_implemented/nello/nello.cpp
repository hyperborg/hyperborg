#include <nello.h>

nello::nello(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Nello");
	manifest.insert("domain","nello");
}

nello::~nello()
{
}

void nello::init()
{
}


