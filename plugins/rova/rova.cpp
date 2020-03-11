#include <rova.h>

rova::rova(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ROVA");
	manifest.insert("domain","rova");
}

rova::~rova()
{
}

void rova::init()
{
}


