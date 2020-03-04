/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GENERIC_THERMOSTAT_H
#define GENERIC_THERMOSTAT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class generic_thermostat : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "generic_thermostat.json");
    Q_INTERFACES(HyPluginInterface);
public:
    generic_thermostat();
    ~generic_thermostat();

    QString name() 		{ return "generic_thermostat"; }
    QString description()	{ return "The generic_thermostat component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif