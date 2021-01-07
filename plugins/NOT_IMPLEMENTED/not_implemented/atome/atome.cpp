#include <atome.h>

atome::atome(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Atome Linky");
	manifest.insert("domain","atome");
}

atome::~atome()
{
}

void atome::init()
{
}


