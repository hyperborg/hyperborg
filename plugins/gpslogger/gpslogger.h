/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef GPSLOGGER_H
#define GPSLOGGER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class gpslogger : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "gpslogger.json");
    Q_INTERFACES(HyPluginInterface);
public:
    gpslogger();
    ~gpslogger();

    QString name() 		{ return "gpslogger"; }
    QString description()	{ return "Support for GPSLogger."; }

protected:
    	void _id();
	void  async_setup();
	void  handle_webhook();
	void  async_setup_entry();
	void  async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif