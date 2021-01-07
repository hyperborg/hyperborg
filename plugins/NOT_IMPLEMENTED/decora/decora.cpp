#include <decora.h>

decora::decora(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Leviton Decora");
	manifest.insert("domain","decora");
}

decora::~decora()
{
}

void decora::init()
{
}


