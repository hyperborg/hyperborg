#include <neurio_energy.h>

neurio_energy::neurio_energy(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Neurio energy");
	manifest.insert("domain","neurio_energy");
}

neurio_energy::~neurio_energy()
{
}

void neurio_energy::init()
{
}


