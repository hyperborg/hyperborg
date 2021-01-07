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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nsw_fuel_station : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nsw_fuel_station.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nsw_fuel_station(QObject *parent=nullptr);
    ~nsw_fuel_station();

    QString name() 		{ return "nsw_fuel_station"; }
    QString description()	{ return "The nsw_fuel_station component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif