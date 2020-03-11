#include <baidu.h>

baidu::baidu(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Baidu");
	manifest.insert("domain","baidu");
}

baidu::~baidu()
{
}

void baidu::init()
{
}


