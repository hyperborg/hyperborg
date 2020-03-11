#include <pushsafer.h>

pushsafer::pushsafer(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pushsafer");
	manifest.insert("domain","pushsafer");
}

pushsafer::~pushsafer()
{
}

void pushsafer::init()
{
}


