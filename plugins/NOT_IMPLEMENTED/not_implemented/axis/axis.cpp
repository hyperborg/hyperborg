#include <axis.h>

axis::axis(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Axis");
	manifest.insert("domain","axis");
}

axis::~axis()
{
}

void axis::init()
{
}

void axis::async_setup()
{
}


void axis::async_setup_entry()
{
}


void axis::async_unload_entry()
{
}


void axis::async_populate_options()
{
}


void axis::async_migrate_entry()
{
}


