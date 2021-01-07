#include <foscam.h>

foscam::foscam(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Foscam");
	manifest.insert("domain","foscam");
}

foscam::~foscam()
{
}

void foscam::init()
{
}


