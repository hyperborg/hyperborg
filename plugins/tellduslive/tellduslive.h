/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TELLDUSLIVE_H
#define TELLDUSLIVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class tellduslive : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tellduslive.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tellduslive();
    ~tellduslive();

    QString name() 		{ return "tellduslive"; }
    QString description()	{ return "Support for Telldus Live."; }

protected:
    	void async_setup_entry();
	void async_new_client();
	void async_setup();
	void async_unload_entry();
	void __init__();
	void async_get_hubs();
	void device_info();
	void identify_device();
	void _discover();
	void update();
	void device();
	void is_available();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif