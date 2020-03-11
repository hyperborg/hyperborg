#include <mjpeg.h>

mjpeg::mjpeg(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","MJPEG IP Camera");
	manifest.insert("domain","mjpeg");
}

mjpeg::~mjpeg()
{
}

void mjpeg::init()
{
}


