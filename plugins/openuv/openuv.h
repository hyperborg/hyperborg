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

class openuv : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "openuv.json");
    Q_INTERFACES(HyPluginInterface);
public:
    openuv();
    ~openuv();

    QString name() 		{ return "openuv"; }
    QString description()	{ return "Support for UV data from openuv.io."; }

protected:
    	void  async_setup();
	void  async_setup_entry();
	void  update_data();
	void  update_uv_index_data();
	void  update_protection_data();
	void  async_unload_entry();
	void  async_migrate_entry();
	void __init__();
	void  async_update_protection_data();
	void  async_update_uv_index_data();
	void  async_update();
	void __init__();
	void available();
	void device_state_attributes();
	void name();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif