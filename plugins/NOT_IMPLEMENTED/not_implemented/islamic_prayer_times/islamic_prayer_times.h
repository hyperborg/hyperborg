/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ISLAMIC_PRAYER_TIMES_H
#define ISLAMIC_PRAYER_TIMES_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class islamic_prayer_times : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "islamic_prayer_times.json");
    Q_INTERFACES(HyPluginInterface);
public:
    islamic_prayer_times(QObject *parent=nullptr);
    ~islamic_prayer_times();

    QString name() 		{ return "islamic_prayer_times"; }
    QString description()	{ return "The islamic_prayer_times component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif