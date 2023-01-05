#include "hud.h"

HUDQMLEngine::HUDQMLEngine(QObject* parent)
    : QQmlApplicationEngine(parent)
{
}

void HUDQMLEngine::logWarnings(const QList<QQmlError>& warnings)
{
    for (int i=0;i<warnings.count();i++)
    {
        log(Info, warnings.at(i).toString());
    }
}

void HUDQMLEngine::log(int severity, QString logline)
{
    qDebug() << "HUDQMLEngine log facility is not implemented: ";
}

void HUDQMLEngine::clearCache()
{
    this->clearComponentCache();
}