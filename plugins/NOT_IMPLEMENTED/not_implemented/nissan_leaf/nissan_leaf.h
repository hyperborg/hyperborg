/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef NISSAN_LEAF_H
#define NISSAN_LEAF_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class nissan_leaf : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "nissan_leaf.json");
    Q_INTERFACES(HyPluginInterface);
public:
    nissan_leaf(QObject *parent=nullptr);
    ~nissan_leaf();

    QString name() 		{ return "nissan_leaf"; }
    QString description()	{ return "Support for the Nissan Leaf Carwings/Nissan Connect API."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void async_handle_update();
	void async_handle_start_charge();
	void setup_leaf();
	void __init__();
	void async_update_data();
	void get_next_interval();
	void async_refresh_data();
	void _extract_start_date();
	void async_get_battery();
	void async_get_climate();
	void async_set_climate();
	void log_registration();
	void device_state_attributes();
	void async_added_to_hass();
	void _update_callback();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif