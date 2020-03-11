#include <ee_brightbox.h>

ee_brightbox::ee_brightbox(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","EE Bright Box");
	manifest.insert("domain","ee_brightbox");
}

ee_brightbox::~ee_brightbox()
{
}

void ee_brightbox::init()
{
}


