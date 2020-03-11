/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef VELBUS_H
#define VELBUS_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class velbus : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "velbus.json");
    Q_INTERFACES(HyPluginInterface);
public:
    velbus(QObject *parent=nullptr);
    ~velbus();

    QString name() 		{ return "velbus"; }
    QString description()	{ return "Support for Velbus devices."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void async_setup_entry();
	void callback();
	void syn_clock();
	void async_unload_entry();
	void __init__();
	void unique_id();
	void should_poll();
	void async_added_to_hass();
	void _on_update();
	void device_info();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif