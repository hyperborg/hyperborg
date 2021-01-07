#include <darksky.h>

darksky::darksky(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Dark Sky");
	manifest.insert("domain","darksky");
}

darksky::~darksky()
{
}

void darksky::init()
{
}


