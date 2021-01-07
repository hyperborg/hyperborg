#include <sht31.h>

sht31::sht31(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sensirion SHT31");
	manifest.insert("domain","sht31");
}

sht31::~sht31()
{
}

void sht31::init()
{
}


