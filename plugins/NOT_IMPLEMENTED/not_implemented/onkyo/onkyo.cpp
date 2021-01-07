#include <onkyo.h>

onkyo::onkyo(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Onkyo");
	manifest.insert("domain","onkyo");
}

onkyo::~onkyo()
{
}

void onkyo::init()
{
}


