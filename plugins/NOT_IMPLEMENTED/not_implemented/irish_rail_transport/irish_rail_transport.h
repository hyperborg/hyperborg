/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef IRISH_RAIL_TRANSPORT_H
#define IRISH_RAIL_TRANSPORT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class irish_rail_transport : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "irish_rail_transport.json");
    Q_INTERFACES(HyPluginInterface);
public:
    irish_rail_transport(QObject *parent=nullptr);
    ~irish_rail_transport();

    QString name() 		{ return "irish_rail_transport"; }
    QString description()	{ return "The irish_rail_transport component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif