/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GEO_LOCATION_H
#define GEO_LOCATION_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class geo_location : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geo_location.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geo_location();
    ~geo_location();

    QString name() 		{ return "geo_location"; }
    QString description()	{ return "Support for Geolocation."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void state();
	void source();
	void distance();
	void latitude();
	void longitude();
	void state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif