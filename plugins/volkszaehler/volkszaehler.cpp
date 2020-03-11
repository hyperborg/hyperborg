#include <volkszaehler.h>

volkszaehler::volkszaehler(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Volkszaehler");
	manifest.insert("domain","volkszaehler");
}

volkszaehler::~volkszaehler()
{
}

void volkszaehler::init()
{
}


