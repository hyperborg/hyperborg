#include <spotify.h>

spotify::spotify(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Spotify");
	manifest.insert("domain","spotify");
}

spotify::~spotify()
{
}

void spotify::init()
{
}

void spotify::async_setup()
{
}


void spotify::async_setup_entry()
{
}


void spotify::async_unload_entry()
{
}


