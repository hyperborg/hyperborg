#include <lockitron.h>

lockitron::lockitron(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Lockitron");
	manifest.insert("domain","lockitron");
}

lockitron::~lockitron()
{
}

void lockitron::init()
{
}


