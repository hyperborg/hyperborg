#include <tod.h>

tod::tod(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Times of the Day");
	manifest.insert("domain","tod");
}

tod::~tod()
{
}

void tod::init()
{
}


