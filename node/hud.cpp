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

bool HUDQMLEngine::eventFilter(QObject* watched, QEvent* event)
{
    if (event->type() == QEvent::KeyPress) 
    {
        QKeyEvent* keyEvent = static_cast<QKeyEvent*>(event);
        qDebug() << "text" << keyEvent->text() << "key" << keyEvent->key() << "modifiers" << keyEvent->modifiers();
    }
    QObject::eventFilter(watched, event);
    return false;
}
