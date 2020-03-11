#include <picotts.h>

picotts::picotts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pico TTS");
	manifest.insert("domain","picotts");
}

picotts::~picotts()
{
}

void picotts::init()
{
}


