#include <temper.h>

temper::temper(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TEMPer");
	manifest.insert("domain","temper");
}

temper::~temper()
{
}

void temper::init()
{
}


