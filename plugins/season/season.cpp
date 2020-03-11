#include <season.h>

season::season(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Season");
	manifest.insert("domain","season");
}

season::~season()
{
}

void season::init()
{
}


