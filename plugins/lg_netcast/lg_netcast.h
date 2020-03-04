/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LG_NETCAST_H
#define LG_NETCAST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lg_netcast : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lg_netcast.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lg_netcast();
    ~lg_netcast();

    QString name() 		{ return "lg_netcast"; }
    QString description()	{ return "The lg_netcast component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif