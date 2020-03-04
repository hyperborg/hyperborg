/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SENSOR_H
#define SENSOR_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class sensor : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "sensor.json");
    Q_INTERFACES(HyPluginInterface);
public:
    sensor();
    ~sensor();

    QString name() 		{ return "sensor"; }
    QString description()	{ return "Component to interface with various sensors that can be monitored."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif