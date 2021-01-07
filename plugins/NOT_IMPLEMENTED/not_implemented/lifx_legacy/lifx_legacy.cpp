#include <lifx_legacy.h>

lifx_legacy::lifx_legacy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LIFX Legacy");
	manifest.insert("domain","lifx_legacy");
}

lifx_legacy::~lifx_legacy()
{
}

void lifx_legacy::init()
{
}


