/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HUAWEI_LTE_H
#define HUAWEI_LTE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class huawei_lte : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "huawei_lte.json");
    Q_INTERFACES(HyPluginInterface);
public:
    huawei_lte();
    ~huawei_lte();

    QString name() 		{ return "huawei_lte"; }
    QString description()	{ return "Support for Huawei LTE routers."; }

protected:
    	void __attrs_post_init__();
	void device_name();
	void device_connections();
	void _get_data();
	void update();
	void logout();
	void cleanup();
	void  async_setup_entry();
	void get_connection();
	void signal_update();
	void _update_router();
	void  async_unload_entry();
	void  async_setup();
	void service_handler();
	void  async_signal_options_update();
	void  async_migrate_entry();
	void _entity_name();
	void _device_unique_id();
	void unique_id();
	void name();
	void available();
	void should_poll();
	void device_info();
	void  async_update();
	void  async_update_options();
	void  async_added_to_hass();
	void  _async_maybe_update();
	void  _async_maybe_update_options();
	void  async_will_remove_from_hass();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif