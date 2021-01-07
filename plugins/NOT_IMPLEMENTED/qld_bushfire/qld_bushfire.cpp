#include <qld_bushfire.h>

qld_bushfire::qld_bushfire(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Queensland Bushfire Alert");
	manifest.insert("domain","qld_bushfire");
}

qld_bushfire::~qld_bushfire()
{
}

void qld_bushfire::init()
{
}


