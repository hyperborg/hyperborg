#include <obihai.h>

obihai::obihai(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Obihai");
	manifest.insert("domain","obihai");
}

obihai::~obihai()
{
}

void obihai::init()
{
}


