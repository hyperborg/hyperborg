#include <edimax.h>

edimax::edimax(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Edimax");
	manifest.insert("domain","edimax");
}

edimax::~edimax()
{
}

void edimax::init()
{
}


