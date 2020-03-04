/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef WAZE_TRAVEL_TIME_H
#define WAZE_TRAVEL_TIME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class waze_travel_time : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "waze_travel_time.json");
    Q_INTERFACES(HyPluginInterface);
public:
    waze_travel_time();
    ~waze_travel_time();

    QString name() 		{ return "waze_travel_time"; }
    QString description()	{ return "The waze_travel_time component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif