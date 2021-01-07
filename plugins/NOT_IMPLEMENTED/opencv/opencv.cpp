#include <opencv.h>

opencv::opencv(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","OpenCV");
	manifest.insert("domain","opencv");
}

opencv::~opencv()
{
}

void opencv::init()
{
}


