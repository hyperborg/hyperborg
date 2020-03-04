/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class counter : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "counter.json");
    Q_INTERFACES(HyPluginInterface);
public:
    counter();
    ~counter();

    QString name() 		{ return "counter"; }
    QString description()	{ return "Component to count within automations."; }

protected:
    	void _none_to_empty_dict();
	void  async_setup();
	void  _process_create_data();
	void _get_suggested_id();
	void  _update_data();
	void __init__();
	void from_yaml();
	void should_poll();
	void icon();
	void state();
	void state_attributes();
	void unique_id();
	void compute_next_state();
	void  async_added_to_hass();
	void async_decrement();
	void async_increment();
	void async_reset();
	void async_configure();
	void  async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif