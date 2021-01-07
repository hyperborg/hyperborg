#include <nanoleaf.h>

nanoleaf::nanoleaf(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Nanoleaf");
	manifest.insert("domain","nanoleaf");
}

nanoleaf::~nanoleaf()
{
}

void nanoleaf::init()
{
}


