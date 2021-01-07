#include <pencom.h>

pencom::pencom(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pencom");
	manifest.insert("domain","pencom");
}

pencom::~pencom()
{
}

void pencom::init()
{
}


