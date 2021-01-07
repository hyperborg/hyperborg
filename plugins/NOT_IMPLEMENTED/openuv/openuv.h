/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef OPENUV_H
#define OPENUV_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class openuv : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openuv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openuv(QObject *parent=nullptr);
    ~openuv();

    QString name() 		{ return "openuv"; }
    QString description()	{ return "Support for UV data from openuv.io."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void update_data();
	void update_uv_index_data();
	void update_protection_data();
	void async_unload_entry();
	void async_migrate_entry();
	void __init__();
	void async_update_protection_data();
	void async_update_uv_index_data();
	void async_update();
	void available();
	void device_state_attributes();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif