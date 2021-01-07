#include <haveibeenpwned.h>

haveibeenpwned::haveibeenpwned(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","HaveIBeenPwned");
	manifest.insert("domain","haveibeenpwned");
}

haveibeenpwned::~haveibeenpwned()
{
}

void haveibeenpwned::init()
{
}


