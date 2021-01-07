#include <xbox_live.h>

xbox_live::xbox_live(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Xbox Live");
	manifest.insert("domain","xbox_live");
}

xbox_live::~xbox_live()
{
}

void xbox_live::init()
{
}


