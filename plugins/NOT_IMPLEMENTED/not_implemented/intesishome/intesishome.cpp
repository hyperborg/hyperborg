#include <intesishome.h>

intesishome::intesishome(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","IntesisHome");
	manifest.insert("domain","intesishome");
}

intesishome::~intesishome()
{
}

void intesishome::init()
{
}


