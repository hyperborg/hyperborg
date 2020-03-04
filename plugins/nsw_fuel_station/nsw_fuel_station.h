/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NSW_FUEL_STATION_H
#define NSW_FUEL_STATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class nsw_fuel_station : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nsw_fuel_station.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nsw_fuel_station();
    ~nsw_fuel_station();

    QString name() 		{ return "nsw_fuel_station"; }
    QString description()	{ return "The nsw_fuel_station component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif