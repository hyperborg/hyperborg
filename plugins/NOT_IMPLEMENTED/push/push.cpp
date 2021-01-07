#include <push.h>

push::push(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Push");
	manifest.insert("domain","push");
}

push::~push()
{
}

void push::init()
{
}


