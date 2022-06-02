#include "hud.h"

HUDQMLEngine::HUDQMLEngine(QObject* parent)
    : QQmlApplicationEngine(parent)
{

}

void HUDQMLEngine::logWarnings(const QList<QQmlError>& warnings)
{
    for (int i=0;i<warnings.count();i++)
    {
        log(0, warnings.at(i).toString());
    }
}

void HUDQMLEngine::log(int severity, QString logline)
{
    emit signal_log(severity, logline, "HUDQMLEngine");
}

void HUDQMLEngine::clearCache()
{
    this->clearComponentCache();
}