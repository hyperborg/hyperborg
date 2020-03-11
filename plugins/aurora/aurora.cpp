#include <aurora.h>

aurora::aurora(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Aurora");
	manifest.insert("domain","aurora");
}

aurora::~aurora()
{
}

void aurora::init()
{
}


