#include <myq.h>

myq::myq(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MyQ");
	manifest.insert("domain","myq");
}

myq::~myq()
{
}

void myq::init()
{
}


