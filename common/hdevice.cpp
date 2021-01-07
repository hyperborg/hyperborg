#include "hdevice.h"

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

