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

