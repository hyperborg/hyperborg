#include <ambiclimate.h>

ambiclimate::ambiclimate(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ambiclimate");
	manifest.insert("domain","ambiclimate");
}

ambiclimate::~ambiclimate()
{
}

void ambiclimate::init()
{
}

void ambiclimate::async_setup()
{
}


void ambiclimate::async_setup_entry()
{
}


