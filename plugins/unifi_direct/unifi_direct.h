/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UNIFI_DIRECT_H
#define UNIFI_DIRECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class unifi_direct : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "unifi_direct.json");
    Q_INTERFACES(HyPluginInterface);
public:
    unifi_direct();
    ~unifi_direct();

    QString name() 		{ return "unifi_direct"; }
    QString description()	{ return "The unifi_direct component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif