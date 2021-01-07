#include <magicseaweed.h>

magicseaweed::magicseaweed(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Magicseaweed");
	manifest.insert("domain","magicseaweed");
}

magicseaweed::~magicseaweed()
{
}

void magicseaweed::init()
{
}


