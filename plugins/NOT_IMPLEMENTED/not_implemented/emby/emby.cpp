#include <emby.h>

emby::emby(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Emby");
	manifest.insert("domain","emby");
}

emby::~emby()
{
}

void emby::init()
{
}


