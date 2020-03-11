#include <london_air.h>

london_air::london_air(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","London Air");
	manifest.insert("domain","london_air");
}

london_air::~london_air()
{
}

void london_air::init()
{
}


