#include <wwlln.h>

wwlln::wwlln(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","World Wide Lightning Location Network (WWLLN)");
	manifest.insert("domain","wwlln");
}

wwlln::~wwlln()
{
}

void wwlln::init()
{
}

void wwlln::async_setup()
{
}


void wwlln::async_setup_entry()
{
}


void wwlln::async_unload_entry()
{
}


void wwlln::async_migrate_entry()
{
}


