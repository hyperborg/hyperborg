#include <socialblade.h>

socialblade::socialblade(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Social Blade");
	manifest.insert("domain","socialblade");
}

socialblade::~socialblade()
{
}

void socialblade::init()
{
}


