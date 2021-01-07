#include <nuki.h>

nuki::nuki(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Nuki");
	manifest.insert("domain","nuki");
}

nuki::~nuki()
{
}

void nuki::init()
{
}


