#include <generic.h>

generic::generic(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Generic");
	manifest.insert("domain","generic");
}

generic::~generic()
{
}

void generic::init()
{
}


