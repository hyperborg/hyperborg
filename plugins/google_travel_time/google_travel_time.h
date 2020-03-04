/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GOOGLE_TRAVEL_TIME_H
#define GOOGLE_TRAVEL_TIME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class google_travel_time : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "google_travel_time.json");
    Q_INTERFACES(HyPluginInterface);
public:
    google_travel_time();
    ~google_travel_time();

    QString name() 		{ return "google_travel_time"; }
    QString description()	{ return "The google_travel_time component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif