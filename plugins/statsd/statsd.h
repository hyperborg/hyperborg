/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STATSD_H
#define STATSD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class statsd : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "statsd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    statsd();
    ~statsd();

    QString name() 		{ return "statsd"; }
    QString description()	{ return "Support for sending data to StatsD."; }

protected:
    	void setup();
	void statsd_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif