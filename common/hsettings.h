#ifndef HSETTINGS_H
#define HSETTINGS_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QVariant>
#include <QMutex>
#include <QMutexLocker>
#include <QSettings>
#include <QVariant>

class HSettings : public QObject
{
Q_OBJECT
public:
    static HSettings *getInstance();

    void setValue(const QString &key, const QVariant &value);
    void setValue(const QString &group, const QString &key, const QVariant &value);


    QVariant value(const QString &key, const QVariant &defaultValue = QVariant()) const;
    QVariant value(const QString &group, const QString &key, const QVariant &defaultValue = QVariant()) const;


private:
    HSettings(QObject *parent=nullptr);
    ~HSettings();
    HSettings *hsettings;

private:
    QSettings *settings;
    QMutex *mutex;
};

#endif