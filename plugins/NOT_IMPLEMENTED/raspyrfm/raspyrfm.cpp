#include <raspyrfm.h>

raspyrfm::raspyrfm(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RaspyRFM");
	manifest.insert("domain","raspyrfm");
}

raspyrfm::~raspyrfm()
{
}

void raspyrfm::init()
{
}


