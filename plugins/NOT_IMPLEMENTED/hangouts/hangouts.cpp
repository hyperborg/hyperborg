#include <hangouts.h>

hangouts::hangouts(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Hangouts");
	manifest.insert("domain","hangouts");
}

hangouts::~hangouts()
{
}

void hangouts::init()
{
}

void hangouts::async_setup()
{
}


void hangouts::async_setup_entry()
{
}


void hangouts::async_unload_entry()
{
}


