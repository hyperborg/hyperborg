#include <statistics.h>

statistics::statistics(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Statistics");
	manifest.insert("domain","statistics");
}

statistics::~statistics()
{
}

void statistics::init()
{
}


