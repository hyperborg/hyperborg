#include <mpchc.h>

mpchc::mpchc(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Media Player Classic Home Cinema (MPC-HC)");
	manifest.insert("domain","mpchc");
}

mpchc::~mpchc()
{
}

void mpchc::init()
{
}


