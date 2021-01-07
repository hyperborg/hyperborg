#include <msteams.h>

msteams::msteams(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Microsoft Teams");
	manifest.insert("domain","msteams");
}

msteams::~msteams()
{
}

void msteams::init()
{
}


