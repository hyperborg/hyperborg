/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WORKDAY_H
#define WORKDAY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class workday : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "workday.json");
    Q_INTERFACES(HyPluginInterface);
public:
    workday();
    ~workday();

    QString name() 		{ return "workday"; }
    QString description()	{ return "Sensor to indicate whether the current day is a workday."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif