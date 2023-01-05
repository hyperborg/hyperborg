#ifndef HUD_H
#define HUD_H

#include <QQmlApplicationEngine>
#include <QQmlError>
#include <QList>
#include <QQmlEngine>

#include "common.h"

class HUDQMLEngine : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit HUDQMLEngine(QObject* parent = nullptr);
    Q_INVOKABLE void clearCache();

protected slots:
    void log(int severity, QString logline);
    void logWarnings(const QList<QQmlError>& warnings);

};

#endif