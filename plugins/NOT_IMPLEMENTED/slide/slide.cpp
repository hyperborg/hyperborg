#include <slide.h>

slide::slide(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Slide");
	manifest.insert("domain","slide");
}

slide::~slide()
{
}

void slide::init()
{
}

void slide::async_setup()
{
}


void slide::update_slides()
{
}


void slide::retry_setup()
{
}


