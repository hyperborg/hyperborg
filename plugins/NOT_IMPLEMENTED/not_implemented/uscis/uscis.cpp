#include <uscis.h>

uscis::uscis(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","U.S. Citizenship and Immigration Services (USCIS)");
	manifest.insert("domain","uscis");
}

uscis::~uscis()
{
}

void uscis::init()
{
}


