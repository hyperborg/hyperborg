/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef APACHE_KAFKA_H
#define APACHE_KAFKA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class apache_kafka : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "apache_kafka.json");
    Q_INTERFACES(HyPluginInterface);
public:
    apache_kafka();
    ~apache_kafka();

    QString name() 		{ return "apache_kafka"; }
    QString description()	{ return "Support for Apache Kafka."; }

protected:
    	void  async_setup();
	void default();
	void __init__();
	void _encode_event();
	void  start();
	void  shutdown();
	void  write();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif