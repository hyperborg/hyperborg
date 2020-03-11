#include <solaredge_local.h>

solaredge_local::solaredge_local(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SolarEdge Local");
	manifest.insert("domain","solaredge_local");
}

solaredge_local::~solaredge_local()
{
}

void solaredge_local::init()
{
}


