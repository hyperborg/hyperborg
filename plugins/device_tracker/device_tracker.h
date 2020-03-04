/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef DEVICE_TRACKER_H
#define DEVICE_TRACKER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class device_tracker : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "device_tracker.json");
    Q_INTERFACES(HyPluginInterface);
public:
    device_tracker();
    ~device_tracker();

    QString name() 		{ return "device_tracker"; }
    QString description()	{ return "Provide functionality to keep track of devices."; }

protected:
    	void is_on();
	void see();
	void async_setup();
	void async_platform_discovered();
	void async_see_service();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif