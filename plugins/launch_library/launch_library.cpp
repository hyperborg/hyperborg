#include <launch_library.h>

launch_library::launch_library(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Launch Library");
	manifest.insert("domain","launch_library");
}

launch_library::~launch_library()
{
}

void launch_library::init()
{
}


