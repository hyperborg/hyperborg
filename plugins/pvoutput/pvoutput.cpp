#include <pvoutput.h>

pvoutput::pvoutput(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","PVOutput");
	manifest.insert("domain","pvoutput");
}

pvoutput::~pvoutput()
{
}

void pvoutput::init()
{
}


