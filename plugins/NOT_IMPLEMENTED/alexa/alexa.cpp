#include <alexa.h>

alexa::alexa(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Amazon Alexa");
	manifest.insert("domain","alexa");
}

alexa::~alexa()
{
}

void alexa::init()
{
}

void alexa::async_setup()
{
}


