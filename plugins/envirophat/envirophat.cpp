#include <envirophat.h>

envirophat::envirophat(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Enviro pHAT");
	manifest.insert("domain","envirophat");
}

envirophat::~envirophat()
{
}

void envirophat::init()
{
}


