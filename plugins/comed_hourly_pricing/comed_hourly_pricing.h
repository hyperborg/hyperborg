/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COMED_HOURLY_PRICING_H
#define COMED_HOURLY_PRICING_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class comed_hourly_pricing : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "comed_hourly_pricing.json");
    Q_INTERFACES(HyPluginInterface);
public:
    comed_hourly_pricing();
    ~comed_hourly_pricing();

    QString name() 		{ return "comed_hourly_pricing"; }
    QString description()	{ return "The comed_hourly_pricing component."; }

protected:
    

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif