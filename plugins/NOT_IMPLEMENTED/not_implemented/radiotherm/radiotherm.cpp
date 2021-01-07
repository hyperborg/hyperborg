#include <radiotherm.h>

radiotherm::radiotherm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Radio Thermostat");
	manifest.insert("domain","radiotherm");
}

radiotherm::~radiotherm()
{
}

void radiotherm::init()
{
}


