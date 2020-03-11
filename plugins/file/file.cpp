#include <file.h>

file::file(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","File");
	manifest.insert("domain","file");
}

file::~file()
{
}

void file::init()
{
}


