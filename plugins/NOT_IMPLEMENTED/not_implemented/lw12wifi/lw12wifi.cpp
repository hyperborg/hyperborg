#include <lw12wifi.h>

lw12wifi::lw12wifi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","LAGUTE LW-12");
	manifest.insert("domain","lw12wifi");
}

lw12wifi::~lw12wifi()
{
}

void lw12wifi::init()
{
}


