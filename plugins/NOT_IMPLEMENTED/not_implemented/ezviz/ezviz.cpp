#include <ezviz.h>

ezviz::ezviz(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ezviz");
	manifest.insert("domain","ezviz");
}

ezviz::~ezviz()
{
}

void ezviz::init()
{
}


