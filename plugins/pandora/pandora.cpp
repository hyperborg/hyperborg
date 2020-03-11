#include <pandora.h>

pandora::pandora(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Pandora");
	manifest.insert("domain","pandora");
}

pandora::~pandora()
{
}

void pandora::init()
{
}


