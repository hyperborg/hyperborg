#include <vicare.h>

vicare::vicare(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","Viessmann ViCare");
	manifest.insert("domain","vicare");
}

vicare::~vicare()
{
}

void vicare::init()
{
}

void vicare::setup()
{
}


