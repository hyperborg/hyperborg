#include <hitron_coda.h>

hitron_coda::hitron_coda(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Rogers Hitron CODA");
	manifest.insert("domain","hitron_coda");
}

hitron_coda::~hitron_coda()
{
}

void hitron_coda::init()
{
}


