/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UPNP_H
#define UPNP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class upnp : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "upnp.json");
    Q_INTERFACES(HyPluginInterface);
public:
    upnp(QObject *parent=nullptr);
    ~upnp();

    QString name() 		{ return "upnp"; }
    QString description()	{ return "Open ports in your router for Home Assistant and provide statistics."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _substitute_hass_ports();
	void async_discover_and_construct();
	void async_setup();
	void async_setup_entry();
	void delete_port_mapping();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif