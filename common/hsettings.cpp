#include "hsettings.h"

HSettings *HSettings::getInstance()
{
    if (hsettings) return hsettings;
    hsettings = new HSettings();
    return hsettings;
}

HSettings::HSettings(QObject *parent) : QObject(parent)
{
    settings = new QSettings("hynode.imi", QSettings::IniFormat, this);
    mutex = new QMutex();
}

HSettings::~HSettings()
{
    mutex->deleteLater();
}

HSettings::setValue(const QString &key, const QVariant &value)
{
    QMutexLocker(mutex);
    QSettings::setValue(key, value);
}

void HSettings::setValue(const QString &group, const QString &key, const QVariant &value)
{
    QMutexLocker(mutex);
    beginGroup(group);
    QSettings::setValue(key, value);
    endGroup();
}

QVariant HSettings::value(const QString &key, const QVariant &defaultValue = QVariant()) const
{
    QMutexLocker(mutex);
    QVariant retval;
    retval=QSettings::value(key, defaultValue);
    return retval;
}

QVariant HSettings::value(const QString &group, const QString &key, const QVariant &defaultValue = QVariant()) const
{
    QMutexLocker(mutex);
    QMutexLocker(mutex);
    QVariant retval;
    beginGroup(group);
    retval=QSettings::value(key, defaultValue);
    endGroup();
    return retval;
}

