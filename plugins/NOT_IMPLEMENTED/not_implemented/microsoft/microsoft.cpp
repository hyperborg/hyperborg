#include <microsoft.h>

microsoft::microsoft(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Microsoft Text-to-Speech (TTS)");
	manifest.insert("domain","microsoft");
}

microsoft::~microsoft()
{
}

void microsoft::init()
{
}


