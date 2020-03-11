#include <niko_home_control.h>

niko_home_control::niko_home_control(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Niko Home Control");
	manifest.insert("domain","niko_home_control");
}

niko_home_control::~niko_home_control()
{
}

void niko_home_control::init()
{
}


