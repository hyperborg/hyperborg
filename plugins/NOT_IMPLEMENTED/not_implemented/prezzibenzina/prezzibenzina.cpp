#include <prezzibenzina.h>

prezzibenzina::prezzibenzina(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Prezzi Benzina");
	manifest.insert("domain","prezzibenzina");
}

prezzibenzina::~prezzibenzina()
{
}

void prezzibenzina::init()
{
}


