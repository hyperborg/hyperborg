#include "hdevice.h"

HDevice::HDevice(QObject *parent) : HyObject(parent)
{}

HDevice::~HDevice() {}

QJsonObject HDevice::configurationTemplate()
{
    QJsonObject obj;
    return obj;
}

void HDevice::saveConfiguration(QJsonObject &json)
{
    Q_UNUSED(json);
}

bool HDevice::loadConfiguration(QJsonObject &json)
{
    Q_UNUSED(json);
    return true;
}

