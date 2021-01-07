#include <stookalert.h>

stookalert::stookalert(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","RIVM Stookalert");
	manifest.insert("domain","stookalert");
}

stookalert::~stookalert()
{
}

void stookalert::init()
{
}


