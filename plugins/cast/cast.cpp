#include <cast.h>

cast::cast(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Cast");
	manifest.insert("domain","cast");
}

cast::~cast()
{
}

void cast::init()
{
}

void cast::async_setup()
{
}


void cast::async_setup_entry()
{
}


