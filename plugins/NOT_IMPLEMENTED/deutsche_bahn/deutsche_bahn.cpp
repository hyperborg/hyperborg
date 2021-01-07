#include <deutsche_bahn.h>

deutsche_bahn::deutsche_bahn(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Deutsche Bahn");
	manifest.insert("domain","deutsche_bahn");
}

deutsche_bahn::~deutsche_bahn()
{
}

void deutsche_bahn::init()
{
}


