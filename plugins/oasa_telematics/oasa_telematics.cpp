#include <oasa_telematics.h>

oasa_telematics::oasa_telematics(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OASA Telematics");
	manifest.insert("domain","oasa_telematics");
}

oasa_telematics::~oasa_telematics()
{
}

void oasa_telematics::init()
{
}


