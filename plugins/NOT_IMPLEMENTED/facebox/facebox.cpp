#include <facebox.h>

facebox::facebox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Facebox");
	manifest.insert("domain","facebox");
}

facebox::~facebox()
{
}

void facebox::init()
{
}


