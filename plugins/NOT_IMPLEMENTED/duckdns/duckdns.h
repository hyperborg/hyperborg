/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DUCKDNS_H
#define DUCKDNS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class duckdns : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "duckdns.json");
    Q_INTERFACES(HyPluginInterface);
public:
    duckdns(QObject *parent=nullptr);
    ~duckdns();

    QString name() 		{ return "duckdns"; }
    QString description()	{ return "Integrate with DuckDNS."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void update_domain_interval();
	void update_domain_service();
	void _update_duckdns();
	void async_track_time_interval_backoff();
	void interval_listener();
	void remove_listener();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif