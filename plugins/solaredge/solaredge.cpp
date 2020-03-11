#include <solaredge.h>

solaredge::solaredge(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SolarEdge");
	manifest.insert("domain","solaredge");
}

solaredge::~solaredge()
{
}

void solaredge::init()
{
}

void solaredge::async_setup()
{
}


void solaredge::async_setup_entry()
{
}


