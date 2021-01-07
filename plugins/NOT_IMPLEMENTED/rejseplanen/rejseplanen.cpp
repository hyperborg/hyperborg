#include <rejseplanen.h>

rejseplanen::rejseplanen(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Rejseplanen");
	manifest.insert("domain","rejseplanen");
}

rejseplanen::~rejseplanen()
{
}

void rejseplanen::init()
{
}


