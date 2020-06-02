#include "hsettings.h"

HSettings::HSettings() : settings(NULL)
{
    mutex = new QMutex();
    useSettings("hynode.imi");
    setValue("current", "use", "1");
}

HSettings::~HSettings()
{
    delete(mutex);
}

void HSettings::deleteSettings()
{
}

void HSettings::useSettings(QString filename)
{
    QMutexLocker locker(mutex);
    if (settings) delete(settings);
    settings = new QSettings(filename, QSettings::IniFormat);
    qDebug() << "settings is now set to " << filename;
    settings->sync();
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
    settings->sync();
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

void HSettings::setValue(const int config_shortcut, QVariant value)
{
    //! Should check input parameters!
    switch(config_shortcut)
    {
	    case Conf_NodeRole: setValue("NodeCore", "role",     value);    break;
        case Conf_MatixId:  setValue("NodeCore", "matrixid", value);    break;
        case Conf_Port:     setValue("NodeCore", "port",     value);    break;
        default:
            break;
    }
}

QVariant HSettings::value(const int config_shortcut)
{
    // We define the default values here, centrally
    switch(config_shortcut)
    {
        case Conf_NodeRole: return value("NodeCore", "role", Undecided); break;
        case Conf_MatixId: return value("NodeCore", "matrixid", "1"); break;
        case Conf_Port: return value("NodeCore", "port", "33334"); break;
        default:
            break;
    }
    return QVariant();
}

int HSettings::mapEnum(QString str)
{
    return 0;
}

QString mapEnum(int idx)
{
    return QString();
}




