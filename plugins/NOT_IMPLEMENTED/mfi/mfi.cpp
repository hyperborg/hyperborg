#include <mfi.h>

mfi::mfi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Ubiquiti mFi mPort");
	manifest.insert("domain","mfi");
}

mfi::~mfi()
{
}

void mfi::init()
{
}


