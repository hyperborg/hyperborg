/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FLEETGO_H
#define FLEETGO_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class fleetgo : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fleetgo.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fleetgo();
    ~fleetgo();

    QString name() 		{ return "fleetgo"; }
    QString description()	{ return "The FleetGO component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif