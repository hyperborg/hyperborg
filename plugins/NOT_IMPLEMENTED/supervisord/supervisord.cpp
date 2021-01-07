#include <supervisord.h>

supervisord::supervisord(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Supervisord");
	manifest.insert("domain","supervisord");
}

supervisord::~supervisord()
{
}

void supervisord::init()
{
}


