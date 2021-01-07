#include <aladdin_connect.h>

aladdin_connect::aladdin_connect(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Aladdin Connect");
	manifest.insert("domain","aladdin_connect");
}

aladdin_connect::~aladdin_connect()
{
}

void aladdin_connect::init()
{
}


