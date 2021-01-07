#include <filesize.h>

filesize::filesize(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","File Size");
	manifest.insert("domain","filesize");
}

filesize::~filesize()
{
}

void filesize::init()
{
}


