/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef RECORDER_H
#define RECORDER_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class recorder : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "recorder.json");
    Q_INTERFACES(HyPluginInterface);
public:
    recorder(QObject *parent=nullptr);
    ~recorder();

    QString name() 		{ return "recorder"; }
    QString description()	{ return "Support for recording details."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void run_information();
	void async_setup();
	void async_handle_purge_service();
	void __init__();
	void async_initialize();
	void do_adhoc_purge();
	void run();
	void connection_failed();
	void register();
	void shutdown();
	void notify_hass_started();
	void async_purge();
	void event_listener();
	void block_till_done();
	void _setup_connection();
	void set_sqlite_pragma();
	void _close_connection();
	void _setup_run();
	void _close_run();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif