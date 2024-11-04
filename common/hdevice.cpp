#include "hdevice.h"

HDevice::HDevice(QObject *parent) : QObject(parent)
{}

HDevice::~HDevice() 
{
}

void HDevice::setHFS(HFS_Interface* h) 
{ 
    hfs = h; 
}

void HDevice::log(int severity, QString logline)
{
    emit signal_log(severity, logline, _id);
}

void HDevice::loadConfiguration(QString str)
{}


