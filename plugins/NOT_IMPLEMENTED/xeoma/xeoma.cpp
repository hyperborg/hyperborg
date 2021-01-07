#include <xeoma.h>

xeoma::xeoma(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xeoma");
	manifest.insert("domain","xeoma");
}

xeoma::~xeoma()
{
}

void xeoma::init()
{
}


