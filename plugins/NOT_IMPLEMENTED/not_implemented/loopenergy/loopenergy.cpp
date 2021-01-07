#include <loopenergy.h>

loopenergy::loopenergy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Loop Energy");
	manifest.insert("domain","loopenergy");
}

loopenergy::~loopenergy()
{
}

void loopenergy::init()
{
}


