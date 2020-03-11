#include <gpmdp.h>

gpmdp::gpmdp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Play Music Desktop Player (GPMDP)");
	manifest.insert("domain","gpmdp");
}

gpmdp::~gpmdp()
{
}

void gpmdp::init()
{
}


