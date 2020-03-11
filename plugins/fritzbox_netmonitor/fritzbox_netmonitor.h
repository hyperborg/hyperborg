/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef FRITZBOX_NETMONITOR_H
#define FRITZBOX_NETMONITOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class fritzbox_netmonitor : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fritzbox_netmonitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fritzbox_netmonitor(QObject *parent=nullptr);
    ~fritzbox_netmonitor();

    QString name() 		{ return "fritzbox_netmonitor"; }
    QString description()	{ return "The fritzbox_netmonitor component."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif