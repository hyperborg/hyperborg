#include <kef.h>

kef::kef(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","KEF");
	manifest.insert("domain","kef");
}

kef::~kef()
{
}

void kef::init()
{
}


