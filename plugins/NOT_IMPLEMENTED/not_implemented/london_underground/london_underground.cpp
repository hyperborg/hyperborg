#include <london_underground.h>

london_underground::london_underground(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","London Underground");
	manifest.insert("domain","london_underground");
}

london_underground::~london_underground()
{
}

void london_underground::init()
{
}


