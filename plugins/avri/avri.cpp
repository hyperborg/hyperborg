#include <avri.h>

avri::avri(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Avri");
	manifest.insert("domain","avri");
}

avri::~avri()
{
}

void avri::init()
{
}


