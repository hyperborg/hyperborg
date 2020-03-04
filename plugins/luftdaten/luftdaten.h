/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef LUFTDATEN_H
#define LUFTDATEN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class luftdaten : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "luftdaten.json");
    Q_INTERFACES(HyPluginInterface);
public:
    luftdaten();
    ~luftdaten();

    QString name() 		{ return "luftdaten"; }
    QString description()	{ return "Support for Luftdaten stations."; }

protected:
    	void _async_fixup_sensor_id();
	void async_setup();
	void async_setup_entry();
	void refresh_sensors();
	void async_unload_entry();
	void __init__();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif