#include <familyhub.h>

familyhub::familyhub(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Samsung Family Hub");
	manifest.insert("domain","familyhub");
}

familyhub::~familyhub()
{
}

void familyhub::init()
{
}


