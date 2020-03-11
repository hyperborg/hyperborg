/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef HTTP_H
#define HTTP_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class http : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "http.json");
    Q_INTERFACES(HyPluginInterface);
public:
    http(QObject *parent=nullptr);
    ~http();

    QString name() 		{ return "http"; }
    QString description()	{ return "Support to serve the Home Assistant API as WSGI application."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void async_get_last_config();
	void __init__();
	void async_setup();
	void stop_server();
	void start_server();
	void register_view();
	void register_redirect();
	void redirect();
	void register_static_path();
	void serve_file();
	void start();
	void stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif