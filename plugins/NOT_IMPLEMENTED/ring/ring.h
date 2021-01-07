/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RING_H
#define RING_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class ring : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "ring.json");
    Q_INTERFACES(HyPluginInterface);
public:
    ring(QObject *parent=nullptr);
    ~ring();

    QString name() 		{ return "ring"; }
    QString description()	{ return "Support for Ring Doorbell/Chimes."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_setup();
	void legacy_cleanup();
	void async_setup_entry();
	void token_updater();
	void async_refresh_all();
	void async_unload_entry();
	void __init__();
	void async_add_listener();
	void async_remove_listener();
	void async_track_device();
	void async_untrack_device();
	void refresh_all();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif