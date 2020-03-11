#include <songpal.h>

songpal::songpal(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Sony Songpal");
	manifest.insert("domain","songpal");
}

songpal::~songpal()
{
}

void songpal::init()
{
}


