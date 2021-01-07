#include <asuswrt.h>

asuswrt::asuswrt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ASUSWRT");
	manifest.insert("domain","asuswrt");
}

asuswrt::~asuswrt()
{
}

void asuswrt::init()
{
}

void asuswrt::async_setup()
{
}


