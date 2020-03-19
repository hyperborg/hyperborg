#include "hsettings.h"

HSettings::HSettings()
{
    settings = new QSettings("hynode.imi", QSettings::IniFormat);
    mutex = new QMutex();
}

HSettings::~HSettings()
{
    delete(mutex);
}

void HSettings::setValue(const QString &key, const QVariant &value)
{
    QMutexLocker locker(mutex);
    settings->setValue(key, value);
}

void HSettings::setValue(const QString &group, const QString &key, const QVariant &value)
{
    QMutexLocker locker(mutex);
    settings->beginGroup(group);
    settings->setValue(key, value);
    settings->endGroup();
}

QVariant HSettings::value(const QString &key, const QVariant &defaultValue) const
{
    QMutexLocker locker(mutex);
    QVariant retval;
    retval=settings->value(key, defaultValue);
    return retval;
}

QVariant HSettings::value(const QString &group, const QString &key, const QVariant &defaultValue) const
{
    QMutexLocker locker(mutex);
    QVariant retval;
    settings->beginGroup(group);
    retval=settings->value(key, defaultValue);
    settings->endGroup();
    return retval;
}

