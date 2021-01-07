#include <ubee.h>

ubee::ubee(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ubee Router");
	manifest.insert("domain","ubee");
}

ubee::~ubee()
{
}

void ubee::init()
{
}


