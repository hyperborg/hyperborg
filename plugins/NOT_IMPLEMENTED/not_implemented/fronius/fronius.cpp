#include <fronius.h>

fronius::fronius(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Fronius");
	manifest.insert("domain","fronius");
}

fronius::~fronius()
{
}

void fronius::init()
{
}


