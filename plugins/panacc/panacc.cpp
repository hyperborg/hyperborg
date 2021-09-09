#include <panacc.h>

PanaCC::PanaCC(QObject *parent) : HyPluginInterface(), HyObject(parent)
{
    init();
}

PanaCC::~PanaCC()
{
}

void PanaCC::init()
{
}

QJsonObject PanaCC::configurationTemplate()
{
    return QJsonObject();
}

void PanaCC::saveConfiguration(QJsonObject& json)
{
    Q_UNUSED(json);
}

bool PanaCC::loadConfiguration(QJsonObject json)
{
    Q_UNUSED(json);
    return true;
}


