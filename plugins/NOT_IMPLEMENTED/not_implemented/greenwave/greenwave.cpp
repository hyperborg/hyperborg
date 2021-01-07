#include <greenwave.h>

greenwave::greenwave(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Greenwave Reality");
	manifest.insert("domain","greenwave");
}

greenwave::~greenwave()
{
}

void greenwave::init()
{
}


