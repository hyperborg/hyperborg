#include <vasttrafik.h>

vasttrafik::vasttrafik(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Västtrafik");
	manifest.insert("domain","vasttrafik");
}

vasttrafik::~vasttrafik()
{
}

void vasttrafik::init()
{
}


