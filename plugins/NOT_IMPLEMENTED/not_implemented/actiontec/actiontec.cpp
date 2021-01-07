#include <actiontec.h>

actiontec::actiontec(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Actiontec");
	manifest.insert("domain","actiontec");
}

actiontec::~actiontec()
{
}

void actiontec::init()
{
}


