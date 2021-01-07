#include <linksys_smart.h>

linksys_smart::linksys_smart(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Linksys Smart Wi-Fi");
	manifest.insert("domain","linksys_smart");
}

linksys_smart::~linksys_smart()
{
}

void linksys_smart::init()
{
}


