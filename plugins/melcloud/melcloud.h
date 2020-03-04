/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef MELCLOUD_H
#define MELCLOUD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class melcloud : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "melcloud.json");
    Q_INTERFACES(HyPluginInterface);
public:
    melcloud();
    ~melcloud();

    QString name() 		{ return "melcloud"; }
    QString description()	{ return "The MELCloud Climate integration."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void __init__();
	void  async_update();
	void  async_set();
	void available();
	void device_id();
	void building_id();
	void device_info();
	void  mel_devices_setup();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif