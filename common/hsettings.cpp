#include "hsettings.h"

HSettings::HSettings() : settings(NULL)
{
    mutex = new QMutex();
    QString settings_file = "hynode.imi";
#ifdef WASM
    settings_file = "/home/web_user/" + settings_file;
#endif
    useSettings(settings_file);
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
        case Conf_IP:       setValue("NodeCore", "ip",       value);    break;
        case Conf_DB_Type:  setValue("NodeCore", "db_type",  value);    break;
        case Conf_DB_Name:  setValue("NodeCore", "db_name",  value);    break;
        case Conf_DB_User:  setValue("NodeCore", "db_user",  value);    break;
        case Conf_DB_Pass:  setValue("NodeCore", "db_pass",  value);    break;
        case Conf_DB_Port:  setValue("NodeCore", "db_port",  value);    break;

        default:
            break;
    }
}

QVariant HSettings::value(const int config_shortcut)
{
    // We define the default values here, centrally
    switch(config_shortcut)
    {
        case Conf_NodeRole: return value("NodeCore", "role", NR_UNDECIDED); break;
        case Conf_MatixId: return value("NodeCore", "matrixid", "1"); break;
        case Conf_Port: return value("NodeCore", "port", "33333"); break;
        case Conf_IP: return value("NodeCore", "ip", "127.0.0.1"); break;
        case Conf_DB_Type: return value("NodeCore", "db_type", "PSQL"); break;
        case Conf_DB_Name: return value("NodeCore", "db_name", ""); break;
        case Conf_DB_User: return value("NodeCore", "db_user", ""); break;
        case Conf_DB_Pass: return value("NodeCore", "db_pass", ""); break;
        case Conf_DB_Port: return value("NodeCore", "db_port", ""); break;

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




