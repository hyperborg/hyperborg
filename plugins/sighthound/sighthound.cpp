#include <sighthound.h>

sighthound::sighthound(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sighthound");
	manifest.insert("domain","sighthound");
}

sighthound::~sighthound()
{
}

void sighthound::init()
{
}


