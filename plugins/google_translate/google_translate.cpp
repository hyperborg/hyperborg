#include <google_translate.h>

google_translate::google_translate(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Google Translate Text-to-Speech");
	manifest.insert("domain","google_translate");
}

google_translate::~google_translate()
{
}

void google_translate::init()
{
}


