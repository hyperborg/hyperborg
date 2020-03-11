#include <kiwi.h>

kiwi::kiwi(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","KIWI");
	manifest.insert("domain","kiwi");
}

kiwi::~kiwi()
{
}

void kiwi::init()
{
}


