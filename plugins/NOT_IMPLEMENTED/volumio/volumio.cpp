#include <volumio.h>

volumio::volumio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Volumio");
	manifest.insert("domain","volumio");
}

volumio::~volumio()
{
}

void volumio::init()
{
}


