#include <mvglive.h>

mvglive::mvglive(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MVG");
	manifest.insert("domain","mvglive");
}

mvglive::~mvglive()
{
}

void mvglive::init()
{
}


