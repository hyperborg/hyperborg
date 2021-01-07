#include <flux.h>

flux::flux(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Flux");
	manifest.insert("domain","flux");
}

flux::~flux()
{
}

void flux::init()
{
}


