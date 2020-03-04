/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NSW_RURAL_FIRE_SERVICE_FEED_H
#define NSW_RURAL_FIRE_SERVICE_FEED_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class nsw_rural_fire_service_feed : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nsw_rural_fire_service_feed.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nsw_rural_fire_service_feed();
    ~nsw_rural_fire_service_feed();

    QString name() 		{ return "nsw_rural_fire_service_feed"; }
    QString description()	{ return "The nsw_rural_fire_service_feed component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif