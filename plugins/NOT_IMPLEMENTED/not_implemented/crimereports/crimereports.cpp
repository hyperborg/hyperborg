#include <crimereports.h>

crimereports::crimereports(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Crime Reports");
	manifest.insert("domain","crimereports");
}

crimereports::~crimereports()
{
}

void crimereports::init()
{
}


