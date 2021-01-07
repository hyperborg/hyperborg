#include <pjlink.h>

pjlink::pjlink(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","PJLink");
	manifest.insert("domain","pjlink");
}

pjlink::~pjlink()
{
}

void pjlink::init()
{
}


