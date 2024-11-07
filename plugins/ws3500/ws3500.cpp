#include <ws3500.h>

ws3500::ws3500(QObject *parent) :  parsecnt(0)
{
}

ws3500::~ws3500()
{
}

void ws3500::loadConfiguration(QString str)
{
    qDebug() << "WS3500 init with HFS: " << hfs;
    _pathbase = "sensors.ws3500.";

    WS3500_Device *device = new WS3500_Device(this);
    devices.insert("0", device);
    device->loadConfiguration("");
}


