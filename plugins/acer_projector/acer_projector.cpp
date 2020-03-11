#include <acer_projector.h>

acer_projector::acer_projector(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Acer Projector");
	manifest.insert("domain","acer_projector");
}

acer_projector::~acer_projector()
{
}

void acer_projector::init()
{
}


