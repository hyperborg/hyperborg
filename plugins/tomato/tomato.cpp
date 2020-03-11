#include <tomato.h>

tomato::tomato(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Tomato");
	manifest.insert("domain","tomato");
}

tomato::~tomato()
{
}

void tomato::init()
{
}


