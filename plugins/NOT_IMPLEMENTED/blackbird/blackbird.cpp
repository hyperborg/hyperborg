#include <blackbird.h>

blackbird::blackbird(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Monoprice Blackbird Matrix Switch");
	manifest.insert("domain","blackbird");
}

blackbird::~blackbird()
{
}

void blackbird::init()
{
}


