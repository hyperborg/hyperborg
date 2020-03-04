/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DWD_WEATHER_WARNINGS_H
#define DWD_WEATHER_WARNINGS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class dwd_weather_warnings : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dwd_weather_warnings.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dwd_weather_warnings();
    ~dwd_weather_warnings();

    QString name() 		{ return "dwd_weather_warnings"; }
    QString description()	{ return "The dwd_weather_warnings component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif