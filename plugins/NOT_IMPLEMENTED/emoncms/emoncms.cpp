#include <emoncms.h>

emoncms::emoncms(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Emoncms");
	manifest.insert("domain","emoncms");
}

emoncms::~emoncms()
{
}

void emoncms::init()
{
}


