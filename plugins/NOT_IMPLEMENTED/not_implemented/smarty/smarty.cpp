#include <smarty.h>

smarty::smarty(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Salda Smarty");
	manifest.insert("domain","smarty");
}

smarty::~smarty()
{
}

void smarty::init()
{
}

void smarty::setup()
{
}


void smarty::poll_device_update()
{
}


