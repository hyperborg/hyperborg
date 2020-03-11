#include <filter.h>

filter::filter(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Filter");
	manifest.insert("domain","filter");
}

filter::~filter()
{
}

void filter::init()
{
}


