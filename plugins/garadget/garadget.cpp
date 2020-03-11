#include <garadget.h>

garadget::garadget(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Garadget");
	manifest.insert("domain","garadget");
}

garadget::~garadget()
{
}

void garadget::init()
{
}


