#include <horizon.h>

horizon::horizon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Unitymedia Horizon HD Recorder");
	manifest.insert("domain","horizon");
}

horizon::~horizon()
{
}

void horizon::init()
{
}


