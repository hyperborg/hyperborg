#include <ted5000.h>

ted5000::ted5000(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","The Energy Detective TED5000");
	manifest.insert("domain","ted5000");
}

ted5000::~ted5000()
{
}

void ted5000::init()
{
}


