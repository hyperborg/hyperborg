#include <essent.h>

essent::essent(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Essent");
	manifest.insert("domain","essent");
}

essent::~essent()
{
}

void essent::init()
{
}


