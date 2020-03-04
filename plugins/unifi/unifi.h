/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef UNIFI_H
#define UNIFI_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class unifi : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "unifi.json");
    Q_INTERFACES(HyPluginInterface);
public:
    unifi();
    ~unifi();

    QString name() 		{ return "unifi"; }
    QString description()	{ return "Support for devices connected to UniFi POE."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void async_load();
	void get_data();
	void update_data();
	void _data_to_save();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif