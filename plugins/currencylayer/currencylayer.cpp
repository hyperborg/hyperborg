#include <currencylayer.h>

currencylayer::currencylayer(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","currencylayer");
	manifest.insert("domain","currencylayer");
}

currencylayer::~currencylayer()
{
}

void currencylayer::init()
{
}


