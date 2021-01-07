#include <lg_soundbar.h>

lg_soundbar::lg_soundbar(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LG Soundbars");
	manifest.insert("domain","lg_soundbar");
}

lg_soundbar::~lg_soundbar()
{
}

void lg_soundbar::init()
{
}


