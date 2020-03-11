#include <brother.h>

brother::brother(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Brother Printer");
	manifest.insert("domain","brother");
}

brother::~brother()
{
}

void brother::init()
{
}

void brother::async_setup()
{
}


void brother::async_setup_entry()
{
}


void brother::async_unload_entry()
{
}


void brother::__init__()
{
}


void brother::async_update()
{
}


