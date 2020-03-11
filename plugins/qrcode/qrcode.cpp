#include <qrcode.h>

qrcode::qrcode(QObject *parent) : QObject(parent)
{
    	manifest.insert("name","QR Code");
	manifest.insert("domain","qrcode");
}

qrcode::~qrcode()
{
}

void qrcode::init()
{
}


