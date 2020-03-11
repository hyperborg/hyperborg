#include <xiaomi.h>

xiaomi::xiaomi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xiaomi");
	manifest.insert("domain","xiaomi");
}

xiaomi::~xiaomi()
{
}

void xiaomi::init()
{
}


