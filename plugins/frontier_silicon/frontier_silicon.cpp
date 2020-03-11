#include <frontier_silicon.h>

frontier_silicon::frontier_silicon(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Frontier Silicon");
	manifest.insert("domain","frontier_silicon");
}

frontier_silicon::~frontier_silicon()
{
}

void frontier_silicon::init()
{
}


