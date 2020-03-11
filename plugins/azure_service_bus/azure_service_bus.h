/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AZURE_SERVICE_BUS_H
#define AZURE_SERVICE_BUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class azure_service_bus : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "azure_service_bus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    azure_service_bus(QObject *parent=nullptr);
    ~azure_service_bus();

    QString name() 		{ return "azure_service_bus"; }
    QString description()	{ return "The Azure Service Bus integration."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif