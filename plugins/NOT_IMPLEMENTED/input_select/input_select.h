/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INPUT_SELECT_H
#define INPUT_SELECT_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class input_select : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "input_select.json");
    Q_INTERFACES(HyPluginInterface);
public:
    input_select(QObject *parent=nullptr);
    ~input_select();

    QString name() 		{ return "input_select"; }
    QString description()	{ return "Support to select an option from a list."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _cv_input_select();
	void async_setup();
	void reload_service_handler();
	void _process_create_data();
	void _get_suggested_id();
	void _update_data();
	void __init__();
	void from_yaml();
	void async_added_to_hass();
	void should_poll();
	void icon();
	void _options();
	void state();
	void state_attributes();
	void unique_id();
	void async_select_option();
	void async_offset_index();
	void async_set_options();
	void async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif