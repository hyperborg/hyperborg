#include <bbox.h>

bbox::bbox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Bbox");
	manifest.insert("domain","bbox");
}

bbox::~bbox()
{
}

void bbox::init()
{
}


