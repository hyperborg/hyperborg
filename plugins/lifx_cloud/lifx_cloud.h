/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LIFX_CLOUD_H
#define LIFX_CLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class lifx_cloud : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "lifx_cloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    lifx_cloud();
    ~lifx_cloud();

    QString name() 		{ return "lifx_cloud"; }
    QString description()	{ return "The lifx_cloud component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif