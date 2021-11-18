#include <huawei_sun.h>

huawei_sun::huawei_sun(QObject *parent) : HyObject(parent)
{
    init();
}

huawei_sun::~huawei_sun()
{
}

void huawei_sun::init()
{
}

QJsonObject huawei_sun::configurationTemplate()
{
    return QJsonObject();
}

void huawei_sun::saveConfiguration(QJsonObject& json)
{
    Q_UNUSED(json);
}

bool huawei_sun::loadConfiguration(QJsonObject json)
{
    Q_UNUSED(json);
    return true;
}

