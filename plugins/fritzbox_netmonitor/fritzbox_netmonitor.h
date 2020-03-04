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

class fritzbox_netmonitor : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "fritzbox_netmonitor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    fritzbox_netmonitor();
    ~fritzbox_netmonitor();

    QString name() 		{ return "fritzbox_netmonitor"; }
    QString description()	{ return "The fritzbox_netmonitor component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif