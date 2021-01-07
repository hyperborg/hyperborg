#include <emulated_roku.h>

emulated_roku::emulated_roku(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Emulated Roku");
	manifest.insert("domain","emulated_roku");
}

emulated_roku::~emulated_roku()
{
}

void emulated_roku::init()
{
}

void emulated_roku::async_setup()
{
}


void emulated_roku::async_setup_entry()
{
}


void emulated_roku::async_unload_entry()
{
}


