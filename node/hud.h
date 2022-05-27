#ifndef HUD_H
#define HUD_H

#include <QQmlApplicationEngine>

class HUDQMLEngine : public QQmlApplicationEngine
{
    Q_OBJECT
public:
    explicit HUDQMLEngine(QObject* parent = nullptr);

    Q_INVOKABLE void clearCache();
};

#endif