#include <recollect_waste.h>

recollect_waste::recollect_waste(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ReCollect Waste");
	manifest.insert("domain","recollect_waste");
}

recollect_waste::~recollect_waste()
{
}

void recollect_waste::init()
{
}


