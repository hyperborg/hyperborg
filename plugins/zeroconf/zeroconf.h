/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZEROCONF_H
#define ZEROCONF_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class zeroconf : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zeroconf.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zeroconf();
    ~zeroconf();

    QString name() 		{ return "zeroconf"; }
    QString description()	{ return "Support for exposing Home Assistant via Zeroconf."; }

protected:
    	void setup();
	void zeroconf_hass_start();
	void service_update();
	void stop_zeroconf();
	void handle_homekit();
	void info_from_service();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif