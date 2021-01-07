/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef AUGUST_H
#define AUGUST_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class august : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "august.json");
    Q_INTERFACES(HyPluginInterface);
public:
    august(QObject *parent=nullptr);
    ~august();

    QString name() 		{ return "august"; }
    QString description()	{ return "Support for August devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_request_validation();
	void async_august_configuration_validation_callback();
	void async_setup_august();
	void async_setup();
	void async_setup_entry();
	void async_unload_entry();
	void __init__();
	void doorbells();
	void locks();
	void get_device_detail();
	void _refresh();
	void _refresh_device_detail_by_ids();
	void _update_device_detail();
	void _get_device_name();
	void lock();
	void unlock();
	void _call_api_op_requires_bridge();
	void _remove_inoperative_doorbells();
	void _remove_inoperative_locks();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif