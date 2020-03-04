/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ADGUARD_H
#define ADGUARD_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class adguard : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "adguard.json");
    Q_INTERFACES(HyPluginInterface);
public:
    adguard();
    ~adguard();

    QString name() 		{ return "adguard"; }
    QString description()	{ return "Support for AdGuard Home."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  add_url();
	void  remove_url();
	void  enable_url();
	void  disable_url();
	void  refresh();
	void  async_unload_entry();
	void __init__();
	void name();
	void icon();
	void entity_registry_enabled_default();
	void available();
	void  async_update();
	void  _adguard_update();
	void device_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif