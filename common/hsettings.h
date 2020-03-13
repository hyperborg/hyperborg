#ifndef HSETTINGS_H
#define HSETTINGS_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QVariant>
#include <QMutex>
#include <QMutexLocker>
#include <QSettings>


class HSettings : public QObject
{
Q_OBJECT
public:
    static HSettings *getInstance();

private:
    HSettings(QObject *parent=nullptr);
    ~HSettings();
    HSettings *hsettings;

private:
    QSettings *settings;
    QMutex *mutex;
};

#endif