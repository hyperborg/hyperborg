#include <solax.h>

solax::solax(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SolaX Power");
	manifest.insert("domain","solax");
}

solax::~solax()
{
}

void solax::init()
{
}


