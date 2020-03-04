/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INPUT_NUMBER_H
#define INPUT_NUMBER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class input_number : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "input_number.json");
    Q_INTERFACES(HyPluginInterface);
public:
    input_number();
    ~input_number();

    QString name() 		{ return "input_number"; }
    QString description()	{ return "Support to set a numeric value from a slider or text box."; }

protected:
    	void _cv_input_number();
	void async_setup();
	void reload_service_handler();
	void _process_create_data();
	void _get_suggested_id();
	void _update_data();
	void __init__();
	void from_yaml();
	void should_poll();
	void _minimum();
	void _maximum();
	void icon();
	void state();
	void _step();
	void unit_of_measurement();
	void unique_id();
	void state_attributes();
	void async_added_to_hass();
	void async_set_value();
	void async_increment();
	void async_decrement();
	void async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif