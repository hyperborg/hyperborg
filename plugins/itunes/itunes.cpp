#include <itunes.h>

itunes::itunes(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Apple iTunes");
	manifest.insert("domain","itunes");
}

itunes::~itunes()
{
}

void itunes::init()
{
}


