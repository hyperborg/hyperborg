#include <intent.h>

intent::intent(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Intent");
	manifest.insert("domain","intent");
}

intent::~intent()
{
}

void intent::init()
{
}

void intent::async_setup()
{
}


void intent::_async_process_intent()
{
}


void intent::post()
{
}


