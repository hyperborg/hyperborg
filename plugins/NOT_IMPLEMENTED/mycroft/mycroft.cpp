#include <mycroft.h>

mycroft::mycroft(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mycroft");
	manifest.insert("domain","mycroft");
}

mycroft::~mycroft()
{
}

void mycroft::init()
{
}

void mycroft::setup()
{
}


