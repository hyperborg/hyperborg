#include <pcal9535a.h>

pcal9535a::pcal9535a(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","PCAL9535A I/O Expander");
	manifest.insert("domain","pcal9535a");
}

pcal9535a::~pcal9535a()
{
}

void pcal9535a::init()
{
}


