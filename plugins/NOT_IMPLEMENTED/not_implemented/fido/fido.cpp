#include <fido.h>

fido::fido(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Fido");
	manifest.insert("domain","fido");
}

fido::~fido()
{
}

void fido::init()
{
}


