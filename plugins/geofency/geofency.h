/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GEOFENCY_H
#define GEOFENCY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class geofency : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "geofency.json");
    Q_INTERFACES(HyPluginInterface);
public:
    geofency();
    ~geofency();

    QString name() 		{ return "geofency"; }
    QString description()	{ return "Support for Geofency."; }

protected:
    	void _address();
	void async_setup();
	void handle_webhook();
	void _is_mobile_beacon();
	void _device_name();
	void _set_location();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif