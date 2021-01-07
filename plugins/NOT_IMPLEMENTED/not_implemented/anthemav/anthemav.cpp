#include <anthemav.h>

anthemav::anthemav(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Anthem A/V Receivers");
	manifest.insert("domain","anthemav");
}

anthemav::~anthemav()
{
}

void anthemav::init()
{
}


