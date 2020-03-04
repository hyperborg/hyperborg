/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GARMIN_CONNECT_H
#define GARMIN_CONNECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class garmin_connect : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "garmin_connect.json");
    Q_INTERFACES(HyPluginInterface);
public:
    garmin_connect();
    ~garmin_connect();

    QString name() 		{ return "garmin_connect"; }
    QString description()	{ return "The Garmin Connect integration."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif