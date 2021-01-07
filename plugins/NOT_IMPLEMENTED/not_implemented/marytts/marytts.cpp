#include <marytts.h>

marytts::marytts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MaryTTS");
	manifest.insert("domain","marytts");
}

marytts::~marytts()
{
}

void marytts::init()
{
}


