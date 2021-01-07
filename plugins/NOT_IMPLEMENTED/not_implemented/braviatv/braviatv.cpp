#include <braviatv.h>

braviatv::braviatv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sony Bravia TV");
	manifest.insert("domain","braviatv");
}

braviatv::~braviatv()
{
}

void braviatv::init()
{
}


