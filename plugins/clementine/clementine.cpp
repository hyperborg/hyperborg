#include <clementine.h>

clementine::clementine(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Clementine Music Player");
	manifest.insert("domain","clementine");
}

clementine::~clementine()
{
}

void clementine::init()
{
}


