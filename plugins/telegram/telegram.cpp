#include <telegram.h>

telegram::telegram(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Telegram");
	manifest.insert("domain","telegram");
}

telegram::~telegram()
{
}

void telegram::init()
{
}


