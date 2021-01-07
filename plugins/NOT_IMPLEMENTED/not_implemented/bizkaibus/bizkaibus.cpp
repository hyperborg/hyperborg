#include <bizkaibus.h>

bizkaibus::bizkaibus(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bizkaibus");
	manifest.insert("domain","bizkaibus");
}

bizkaibus::~bizkaibus()
{
}

void bizkaibus::init()
{
}


