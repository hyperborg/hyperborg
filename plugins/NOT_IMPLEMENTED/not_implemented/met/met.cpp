#include <met.h>

met::met(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Meteorologisk institutt (Met.no)");
	manifest.insert("domain","met");
}

met::~met()
{
}

void met::init()
{
}

void met::async_setup()
{
}


void met::async_setup_entry()
{
}


void met::async_unload_entry()
{
}


