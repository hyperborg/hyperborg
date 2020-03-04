/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LINUX_BATTERY_H
#define LINUX_BATTERY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class linux_battery : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "linux_battery.json");
    Q_INTERFACES(HyPluginInterface);
public:
    linux_battery();
    ~linux_battery();

    QString name() 		{ return "linux_battery"; }
    QString description()	{ return "The linux_battery component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif