/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class stream : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "stream.json");
    Q_INTERFACES(HyPluginInterface);
public:
    stream(QObject *parent=nullptr);
    ~stream();

    QString name() 		{ return "stream"; }
    QString description()	{ return "Provide functionality to stream video source."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void request_stream();
	void async_setup();
	void shutdown();
	void async_record();
	void __init__();
	void outputs();
	void add_provider();
	void remove_provider();
	void check_idle();
	void start();
	void stop();
	void _stop();
	void async_handle_record_service();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif