#include <prowl.h>

prowl::prowl(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Prowl");
	manifest.insert("domain","prowl");
}

prowl::~prowl()
{
}

void prowl::init()
{
}


