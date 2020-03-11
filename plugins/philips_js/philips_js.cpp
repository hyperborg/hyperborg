#include <philips_js.h>

philips_js::philips_js(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Philips TV");
	manifest.insert("domain","philips_js");
}

philips_js::~philips_js()
{
}

void philips_js::init()
{
}


