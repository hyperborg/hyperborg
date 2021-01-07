#include <ampio.h>

ampio::ampio(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ampio Smart Smog System");
	manifest.insert("domain","ampio");
}

ampio::~ampio()
{
}

void ampio::init()
{
}


