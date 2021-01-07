#include <proxy.h>

proxy::proxy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Camera Proxy");
	manifest.insert("domain","proxy");
}

proxy::~proxy()
{
}

void proxy::init()
{
}


