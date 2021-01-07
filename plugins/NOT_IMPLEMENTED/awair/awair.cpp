#include <awair.h>

awair::awair(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Awair");
	manifest.insert("domain","awair");
}

awair::~awair()
{
}

void awair::init()
{
}


