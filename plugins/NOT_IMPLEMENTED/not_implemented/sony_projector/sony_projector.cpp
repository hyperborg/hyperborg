#include <sony_projector.h>

sony_projector::sony_projector(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sony Projector");
	manifest.insert("domain","sony_projector");
}

sony_projector::~sony_projector()
{
}

void sony_projector::init()
{
}


