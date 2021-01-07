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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class dwd_weather_warnings : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dwd_weather_warnings.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dwd_weather_warnings(QObject *parent=nullptr);
    ~dwd_weather_warnings();

    QString name() 		{ return "dwd_weather_warnings"; }
    QString description()	{ return "The dwd_weather_warnings component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif