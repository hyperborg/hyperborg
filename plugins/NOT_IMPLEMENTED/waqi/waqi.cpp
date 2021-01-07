#include <waqi.h>

waqi::waqi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","World Air Quality Index (WAQI)");
	manifest.insert("domain","waqi");
}

waqi::~waqi()
{
}

void waqi::init()
{
}


