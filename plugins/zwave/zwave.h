/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ZWAVE_H
#define ZWAVE_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class zwave : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "zwave.json");
    Q_INTERFACES(HyPluginInterface);
public:
    zwave();
    ~zwave();

    QString name() 		{ return "zwave"; }
    QString description()	{ return "Support for Z-Wave."; }

protected:
    	void _obj_to_dict();
	void _value_name();
	void nice_print_node();
	void get_config_value();
	void  async_setup_platform();
	void  async_setup();
	void  async_setup_entry();
	void log_all();
	void value_added();
	void node_added();
	void  _add_node_to_component();
	void _on_ready();
	void _on_timeout();
	void node_removed();
	void  _remove_device();
	void network_ready();
	void network_complete();
	void network_complete_some_dead();
	void add_node();
	void add_node_secure();
	void remove_node();
	void cancel_command();
	void heal_network();
	void soft_reset();
	void test_network();
	void stop_network();
	void  rename_node();
	void  rename_value();
	void set_poll_intensity();
	void remove_failed_node();
	void replace_failed_node();
	void set_config_parameter();
	void refresh_node_value();
	void set_node_value();
	void print_config_parameter();
	void print_node();
	void set_wakeup();
	void change_association();
	void  async_refresh_entity();
	void refresh_node();
	void reset_node_meters();
	void heal_node();
	void test_node();
	void start_zwave();
	void  _check_awaked();
	void _finalize_start();
	void __init__();
	void __getattr__();
	void __iter__();
	void check_value();
	void _check_entity_ready();
	void _on_ready();
	void _on_timeout();
	void  discover_device();
	void __init__();
	void network_value_changed();
	void value_added();
	void value_changed();
	void  value_renamed();
	void  async_added_to_hass();
	void _update_attributes();
	void update_properties();
	void should_poll();
	void unique_id();
	void device_info();
	void name();
	void device_state_attributes();
	void refresh_from_network();
	void _compute_unique_id();
	void compute_value_unique_id();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif