#include <openevse.h>

openevse::openevse(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenEVSE");
	manifest.insert("domain","openevse");
}

openevse::~openevse()
{
}

void openevse::init()
{
}


