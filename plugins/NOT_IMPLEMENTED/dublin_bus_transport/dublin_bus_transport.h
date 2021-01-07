/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DUBLIN_BUS_TRANSPORT_H
#define DUBLIN_BUS_TRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class dublin_bus_transport : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "dublin_bus_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    dublin_bus_transport(QObject *parent=nullptr);
    ~dublin_bus_transport();

    QString name() 		{ return "dublin_bus_transport"; }
    QString description()	{ return "The dublin_bus_transport component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif