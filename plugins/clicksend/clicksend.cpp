#include <clicksend.h>

clicksend::clicksend(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","ClickSend SMS");
	manifest.insert("domain","clicksend");
}

clicksend::~clicksend()
{
}

void clicksend::init()
{
}


