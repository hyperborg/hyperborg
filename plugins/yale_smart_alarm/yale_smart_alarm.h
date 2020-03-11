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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class yale_smart_alarm : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "yale_smart_alarm.json");
    Q_INTERFACES(HyPluginInterface);
public:
    yale_smart_alarm(QObject *parent=nullptr);
    ~yale_smart_alarm();

    QString name() 		{ return "yale_smart_alarm"; }
    QString description()	{ return "The yale_smart_alarm component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif