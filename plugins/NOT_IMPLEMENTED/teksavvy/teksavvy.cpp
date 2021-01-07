#include <teksavvy.h>

teksavvy::teksavvy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","TekSavvy");
	manifest.insert("domain","teksavvy");
}

teksavvy::~teksavvy()
{
}

void teksavvy::init()
{
}


