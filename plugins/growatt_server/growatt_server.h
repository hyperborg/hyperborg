/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GROWATT_SERVER_H
#define GROWATT_SERVER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class growatt_server : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "growatt_server.json");
    Q_INTERFACES(HyPluginInterface);
public:
    growatt_server();
    ~growatt_server();

    QString name() 		{ return "growatt_server"; }
    QString description()	{ return "The Growatt server PV inverter sensor integration."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif