#include <thomson.h>

thomson::thomson(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Thomson");
	manifest.insert("domain","thomson");
}

thomson::~thomson()
{
}

void thomson::init()
{
}


