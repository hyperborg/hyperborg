#include <ddwrt.h>

ddwrt::ddwrt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DD-WRT");
	manifest.insert("domain","ddwrt");
}

ddwrt::~ddwrt()
{
}

void ddwrt::init()
{
}


