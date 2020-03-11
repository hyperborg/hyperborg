#include <sesame.h>

sesame::sesame(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sesame Smart Lock");
	manifest.insert("domain","sesame");
}

sesame::~sesame()
{
}

void sesame::init()
{
}


