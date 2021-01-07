#include <rainforest_eagle.h>

rainforest_eagle::rainforest_eagle(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Rainforest Eagle-200");
	manifest.insert("domain","rainforest_eagle");
}

rainforest_eagle::~rainforest_eagle()
{
}

void rainforest_eagle::init()
{
}


