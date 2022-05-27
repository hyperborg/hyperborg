#include "hud.h"

HUDQMLEngine::HUDQMLEngine(QObject* parent)
    : QQmlApplicationEngine(parent)
{

}

void HUDQMLEngine::clearCache()
{
    this->clearComponentCache();
}