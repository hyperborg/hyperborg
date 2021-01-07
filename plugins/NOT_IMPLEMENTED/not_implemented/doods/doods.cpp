#include <doods.h>

doods::doods(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DOODS - Distributed Outside Object Detection Service");
	manifest.insert("domain","doods");
}

doods::~doods()
{
}

void doods::init()
{
}


