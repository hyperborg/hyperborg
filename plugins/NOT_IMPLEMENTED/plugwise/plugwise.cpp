#include <plugwise.h>

plugwise::plugwise(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Plugwise Anna");
	manifest.insert("domain","plugwise");
}

plugwise::~plugwise()
{
}

void plugwise::init()
{
}


