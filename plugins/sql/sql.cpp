#include <sql.h>

sql::sql(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SQL");
	manifest.insert("domain","sql");
}

sql::~sql()
{
}

void sql::init()
{
}


