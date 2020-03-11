#include <smtp.h>

smtp::smtp(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","SMTP");
	manifest.insert("domain","smtp");
}

smtp::~smtp()
{
}

void smtp::init()
{
}


