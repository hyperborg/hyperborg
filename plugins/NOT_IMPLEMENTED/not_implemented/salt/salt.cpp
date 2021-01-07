#include <salt.h>

salt::salt(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Salt Fiber Box");
	manifest.insert("domain","salt");
}

salt::~salt()
{
}

void salt::init()
{
}


