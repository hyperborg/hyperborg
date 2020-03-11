#include <delijn.h>

delijn::delijn(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","De Lijn");
	manifest.insert("domain","delijn");
}

delijn::~delijn()
{
}

void delijn::init()
{
}


