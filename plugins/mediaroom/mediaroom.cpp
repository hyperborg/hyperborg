#include <mediaroom.h>

mediaroom::mediaroom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mediaroom");
	manifest.insert("domain","mediaroom");
}

mediaroom::~mediaroom()
{
}

void mediaroom::init()
{
}


