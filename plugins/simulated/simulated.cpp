#include <simulated.h>

simulated::simulated(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Simulated");
	manifest.insert("domain","simulated");
}

simulated::~simulated()
{
}

void simulated::init()
{
}


