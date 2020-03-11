#include <keyboard.h>

keyboard::keyboard(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Keyboard");
	manifest.insert("domain","keyboard");
}

keyboard::~keyboard()
{
}

void keyboard::init()
{
}

void keyboard::setup()
{
}


