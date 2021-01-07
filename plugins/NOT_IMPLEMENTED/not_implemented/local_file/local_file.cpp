#include <local_file.h>

local_file::local_file(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Local File");
	manifest.insert("domain","local_file");
}

local_file::~local_file()
{
}

void local_file::init()
{
}


