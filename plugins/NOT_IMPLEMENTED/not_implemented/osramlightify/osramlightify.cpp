#include <osramlightify.h>

osramlightify::osramlightify(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Osramlightify");
	manifest.insert("domain","osramlightify");
}

osramlightify::~osramlightify()
{
}

void osramlightify::init()
{
}


