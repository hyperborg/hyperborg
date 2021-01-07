#include <fitbit.h>

fitbit::fitbit(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Fitbit");
	manifest.insert("domain","fitbit");
}

fitbit::~fitbit()
{
}

void fitbit::init()
{
}


