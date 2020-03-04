/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INFLUXDB_H
#define INFLUXDB_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class influxdb : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "influxdb.json");
    Q_INTERFACES(HyPluginInterface);
public:
    influxdb();
    ~influxdb();

    QString name() 		{ return "influxdb"; }
    QString description()	{ return "Support for sending data to an Influx database."; }

protected:
    	void setup();
	void event_to_json();
	void shutdown();
	void __init__();
	void _event_listener();
	void batch_timeout();
	void get_events_json();
	void write_to_influxdb();
	void run();
	void block_till_done();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif