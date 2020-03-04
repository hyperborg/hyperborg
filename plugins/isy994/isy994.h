/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef ISY994_H
#define ISY994_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class isy994 : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "isy994.json");
    Q_INTERFACES(HyPluginInterface);
public:
    isy994();
    ~isy994();

    QString name() 		{ return "isy994"; }
    QString description()	{ return "Support the ISY-994 controllers."; }

protected:
    	void _check_for_node_def();
	void # Node doesn't have a node_();
	void _check_for_insteon_type();
	void _check_for_uom_id();
	void _check_for_states_in_uom();
	void _is_sensor_a_binary_sensor();
	void _categorize_nodes();
	void _categorize_programs();
	void _categorize_weather();
	void setup();
	void stop();
	void __init__();
	void  async_added_to_hass();
	void on_update();
	void on_control();
	void unique_id();
	void name();
	void should_poll();
	void value();
	void is_unknown();
	void state();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif