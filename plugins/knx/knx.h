/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef KNX_H
#define KNX_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class knx : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "knx.json");
    Q_INTERFACES(HyPluginInterface);
public:
    knx(QObject *parent=nullptr);
    ~knx();

    QString name() 		{ return "knx"; }
    QString description()	{ return "Support KNX devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void _get_devices();
	void __init__();
	void init_xknx();
	void start();
	void stop();
	void config_file();
	void connection_config();
	void connection_config_routing();
	void connection_config_tunneling();
	void connection_config_auto();
	void register_callbacks();
	void async_create_exposures();
	void telegram_received_cb();
	void service_send_to_knx_bus();
	void calculate_payload();
	void async_register();
	void _async_entity_changed();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif