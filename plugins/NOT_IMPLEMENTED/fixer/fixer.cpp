#include <fixer.h>

fixer::fixer(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Fixer");
	manifest.insert("domain","fixer");
}

fixer::~fixer()
{
}

void fixer::init()
{
}


