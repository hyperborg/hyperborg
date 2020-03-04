/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef EDDYSTONE_TEMPERATURE_H
#define EDDYSTONE_TEMPERATURE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class eddystone_temperature : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "eddystone_temperature.json");
    Q_INTERFACES(HyPluginInterface);
public:
    eddystone_temperature();
    ~eddystone_temperature();

    QString name() 		{ return "eddystone_temperature"; }
    QString description()	{ return "The eddystone_temperature component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif