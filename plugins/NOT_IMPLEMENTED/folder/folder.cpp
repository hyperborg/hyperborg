#include <folder.h>

folder::folder(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Folder");
	manifest.insert("domain","folder");
}

folder::~folder()
{
}

void folder::init()
{
}


