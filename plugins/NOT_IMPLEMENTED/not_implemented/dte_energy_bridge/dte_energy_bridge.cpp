#include <dte_energy_bridge.h>

dte_energy_bridge::dte_energy_bridge(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","DTE Energy Bridge");
	manifest.insert("domain","dte_energy_bridge");
}

dte_energy_bridge::~dte_energy_bridge()
{
}

void dte_energy_bridge::init()
{
}


