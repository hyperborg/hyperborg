#include <gitter.h>

gitter::gitter(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Gitter");
	manifest.insert("domain","gitter");
}

gitter::~gitter()
{
}

void gitter::init()
{
}


