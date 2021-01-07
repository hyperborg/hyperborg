#include <aruba.h>

aruba::aruba(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Aruba");
	manifest.insert("domain","aruba");
}

aruba::~aruba()
{
}

void aruba::init()
{
}


