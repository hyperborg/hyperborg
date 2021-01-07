#include <co2signal.h>

co2signal::co2signal(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","CO2 Signal");
	manifest.insert("domain","co2signal");
}

co2signal::~co2signal()
{
}

void co2signal::init()
{
}


