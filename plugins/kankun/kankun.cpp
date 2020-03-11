#include <kankun.h>

kankun::kankun(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Kankun");
	manifest.insert("domain","kankun");
}

kankun::~kankun()
{
}

void kankun::init()
{
}


