#include <xfinity.h>

xfinity::xfinity(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xfinity Gateway");
	manifest.insert("domain","xfinity");
}

xfinity::~xfinity()
{
}

void xfinity::init()
{
}


