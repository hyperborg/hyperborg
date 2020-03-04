/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INPUT_TEXT_H
#define INPUT_TEXT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class input_text : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "input_text.json");
    Q_INTERFACES(HyPluginInterface);
public:
    input_text();
    ~input_text();

    QString name() 		{ return "input_text"; }
    QString description()	{ return "Support to enter a value into a text box."; }

protected:
    	void _cv_input_text();
	void  async_setup();
	void  reload_service_handler();
	void  _process_create_data();
	void _get_suggested_id();
	void  _update_data();
	void __init__();
	void from_yaml();
	void should_poll();
	void icon();
	void _maximum();
	void _minimum();
	void state();
	void unit_of_measurement();
	void unique_id();
	void state_attributes();
	void  async_added_to_hass();
	void  async_set_value();
	void  async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif