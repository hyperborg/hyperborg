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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class statsd : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "statsd.json");
    Q_INTERFACES(HyPluginInterface);
public:
    statsd(QObject *parent=nullptr);
    ~statsd();

    QString name() 		{ return "statsd"; }
    QString description()	{ return "Support for sending data to StatsD."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void statsd_event_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif