/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INPUT_BOOLEAN_H
#define INPUT_BOOLEAN_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class input_boolean : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "input_boolean.json");
    Q_INTERFACES(HyPluginInterface);
public:
    input_boolean(QObject *parent=nullptr);
    ~input_boolean();

    QString name() 		{ return "input_boolean"; }
    QString description()	{ return "Support to keep track of user controlled booleans for within automation."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _process_create_data();
	void _get_suggested_id();
	void _update_data();
	void is_on();
	void async_setup();
	void reload_service_handler();
	void __init__();
	void should_poll();
	void state_attributes();
	void icon();
	void unique_id();
	void async_added_to_hass();
	void async_turn_on();
	void async_turn_off();
	void async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif