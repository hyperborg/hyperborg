#include <iglo.h>

iglo::iglo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","iGlo");
	manifest.insert("domain","iglo");
}

iglo::~iglo()
{
}

void iglo::init()
{
}


