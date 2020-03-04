/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef YALE_SMART_ALARM_H
#define YALE_SMART_ALARM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class yale_smart_alarm : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yale_smart_alarm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yale_smart_alarm();
    ~yale_smart_alarm();

    QString name() 		{ return "yale_smart_alarm"; }
    QString description()	{ return "The yale_smart_alarm component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif