#include <todoist.h>

todoist::todoist(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Todoist");
	manifest.insert("domain","todoist");
}

todoist::~todoist()
{
}

void todoist::init()
{
}


