#include <russound_rio.h>

russound_rio::russound_rio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Russound RIO");
	manifest.insert("domain","russound_rio");
}

russound_rio::~russound_rio()
{
}

void russound_rio::init()
{
}


