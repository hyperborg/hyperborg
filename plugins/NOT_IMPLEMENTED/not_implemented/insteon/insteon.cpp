#include <insteon.h>

insteon::insteon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Insteon");
	manifest.insert("domain","insteon");
}

insteon::~insteon()
{
}

void insteon::init()
{
}

void insteon::async_setup()
{
}


