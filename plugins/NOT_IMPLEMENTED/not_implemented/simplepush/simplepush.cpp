#include <simplepush.h>

simplepush::simplepush(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Simplepush");
	manifest.insert("domain","simplepush");
}

simplepush::~simplepush()
{
}

void simplepush::init()
{
}


