#include <switchmate.h>

switchmate::switchmate(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Switchmate SimplySmart Home");
	manifest.insert("domain","switchmate");
}

switchmate::~switchmate()
{
}

void switchmate::init()
{
}


