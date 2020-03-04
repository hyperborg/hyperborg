/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VESYNC_H
#define VESYNC_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class vesync : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "vesync.json");
    Q_INTERFACES(HyPluginInterface);
public:
    vesync();
    ~vesync();

    QString name() 		{ return "vesync"; }
    QString description()	{ return "Etekcity VeSync integration."; }

protected:
    	void async_setup();
	void async_setup_entry();
	void async_new_device_discovery();
	void async_unload_entry();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif