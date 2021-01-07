/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef INPUT_DATETIME_H
#define INPUT_DATETIME_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class input_datetime : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "input_datetime.json");
    Q_INTERFACES(HyPluginInterface);
public:
    input_datetime(QObject *parent=nullptr);
    ~input_datetime();

    QString name() 		{ return "input_datetime"; }
    QString description()	{ return "Support to select a date and/or a time."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void has_date_or_time();
	void async_setup();
	void reload_service_handler();
	void async_set_datetime_service();
	void _process_create_data();
	void _get_suggested_id();
	void _update_data();
	void __init__();
	void from_yaml();
	void async_added_to_hass();
	void should_poll();
	void has_date();
	void has_time();
	void icon();
	void state();
	void state_attributes();
	void unique_id();
	void async_set_datetime();
	void async_update_config();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif