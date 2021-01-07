#include <hp_ilo.h>

hp_ilo::hp_ilo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HP Integrated Lights-Out (ILO)");
	manifest.insert("domain","hp_ilo");
}

hp_ilo::~hp_ilo()
{
}

void hp_ilo::init()
{
}


