#include <random.h>

random::random(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Random");
	manifest.insert("domain","random");
}

random::~random()
{
}

void random::init()
{
}


