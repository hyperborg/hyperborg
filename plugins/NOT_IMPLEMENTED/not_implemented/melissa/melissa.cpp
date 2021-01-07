#include <melissa.h>

melissa::melissa(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Melissa");
	manifest.insert("domain","melissa");
}

melissa::~melissa()
{
}

void melissa::init()
{
}

void melissa::async_setup()
{
}


