#include <miflora.h>

miflora::miflora(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mi Flora");
	manifest.insert("domain","miflora");
}

miflora::~miflora()
{
}

void miflora::init()
{
}


