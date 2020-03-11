#include <aquostv.h>

aquostv::aquostv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sharp Aquos TV");
	manifest.insert("domain","aquostv");
}

aquostv::~aquostv()
{
}

void aquostv::init()
{
}


