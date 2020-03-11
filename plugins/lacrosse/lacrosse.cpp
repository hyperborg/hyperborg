#include <lacrosse.h>

lacrosse::lacrosse(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LaCrosse");
	manifest.insert("domain","lacrosse");
}

lacrosse::~lacrosse()
{
}

void lacrosse::init()
{
}


