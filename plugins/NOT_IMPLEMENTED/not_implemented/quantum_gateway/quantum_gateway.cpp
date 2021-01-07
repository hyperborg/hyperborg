#include <quantum_gateway.h>

quantum_gateway::quantum_gateway(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Quantum Gateway");
	manifest.insert("domain","quantum_gateway");
}

quantum_gateway::~quantum_gateway()
{
}

void quantum_gateway::init()
{
}


