#include <mold_indicator.h>

mold_indicator::mold_indicator(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Mold Indicator");
	manifest.insert("domain","mold_indicator");
}

mold_indicator::~mold_indicator()
{
}

void mold_indicator::init()
{
}


