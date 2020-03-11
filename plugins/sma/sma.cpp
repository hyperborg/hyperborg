#include <sma.h>

sma::sma(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SMA Solar");
	manifest.insert("domain","sma");
}

sma::~sma()
{
}

void sma::init()
{
}


