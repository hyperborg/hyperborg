/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef TESLA_H
#define TESLA_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class tesla : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "tesla.json");
    Q_INTERFACES(HyPluginInterface);
public:
    tesla(QObject *parent=nullptr);
    ~tesla();

    QString name() 		{ return "tesla"; }
    QString description()	{ return "Support for Tesla cars."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void _async_save_tokens();
	void async_setup();
	void _update_entry();
	void async_setup_entry();
	void async_unload_entry();
	void update_listener();
	void __init__();
	void unique_id();
	void icon();
	void should_poll();
	void device_state_attributes();
	void device_info();
	void async_added_to_hass();
	void async_will_remove_from_hass();
	void async_update();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif