#include <oru.h>

oru::oru(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Orange and Rockland Utility (ORU)");
	manifest.insert("domain","oru");
}

oru::~oru()
{
}

void oru::init()
{
}


