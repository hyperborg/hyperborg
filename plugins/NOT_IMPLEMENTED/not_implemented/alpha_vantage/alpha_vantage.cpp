#include <alpha_vantage.h>

alpha_vantage::alpha_vantage(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Alpha Vantage");
	manifest.insert("domain","alpha_vantage");
}

alpha_vantage::~alpha_vantage()
{
}

void alpha_vantage::init()
{
}


