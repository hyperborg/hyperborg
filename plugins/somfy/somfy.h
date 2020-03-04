/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef SOMFY_H
#define SOMFY_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class somfy : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "somfy.json");
    Q_INTERFACES(HyPluginInterface);
public:
    somfy();
    ~somfy();

    QString name() 		{ return "somfy"; }
    QString description()	{ return "Support for Somfy hubs."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  async_unload_entry();
	void __init__();
	void unique_id();
	void name();
	void device_info();
	void  async_update();
	void has_capability();
	void  update_all_devices();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif