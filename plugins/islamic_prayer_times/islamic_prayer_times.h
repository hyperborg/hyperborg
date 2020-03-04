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

class islamic_prayer_times : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "islamic_prayer_times.json");
    Q_INTERFACES(HyPluginInterface);
public:
    islamic_prayer_times();
    ~islamic_prayer_times();

    QString name() 		{ return "islamic_prayer_times"; }
    QString description()	{ return "The islamic_prayer_times component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif