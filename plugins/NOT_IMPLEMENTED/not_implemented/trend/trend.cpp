#include <trend.h>

trend::trend(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Trend");
	manifest.insert("domain","trend");
}

trend::~trend()
{
}

void trend::init()
{
}


