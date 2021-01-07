#include <starlingbank.h>

starlingbank::starlingbank(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Starling Bank");
	manifest.insert("domain","starlingbank");
}

starlingbank::~starlingbank()
{
}

void starlingbank::init()
{
}


