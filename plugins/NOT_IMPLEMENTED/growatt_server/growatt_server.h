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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class growatt_server : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "growatt_server.json");
    Q_INTERFACES(HyPluginInterface);
public:
    growatt_server(QObject *parent=nullptr);
    ~growatt_server();

    QString name() 		{ return "growatt_server"; }
    QString description()	{ return "The Growatt server PV inverter sensor integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif