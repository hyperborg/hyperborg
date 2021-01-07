#include <monoprice.h>

monoprice::monoprice(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Monoprice 6-Zone Amplifier");
	manifest.insert("domain","monoprice");
}

monoprice::~monoprice()
{
}

void monoprice::init()
{
}


