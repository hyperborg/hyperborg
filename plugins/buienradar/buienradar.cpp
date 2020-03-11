#include <buienradar.h>

buienradar::buienradar(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Buienradar");
	manifest.insert("domain","buienradar");
}

buienradar::~buienradar()
{
}

void buienradar::init()
{
}


