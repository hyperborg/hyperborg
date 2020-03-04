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

class http : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "http.json");
    Q_INTERFACES(HyPluginInterface);
public:
    http();
    ~http();

    QString name() 		{ return "http"; }
    QString description()	{ return "Support to serve the Home Assistant API as WSGI application."; }

protected:
    	void  async_get_last_config();
	void __init__();
	void  async_setup();
	void  stop_server();
	void  start_server();
	void __init__();
	void register_view();
	void register_redirect();
	void  redirect();
	void register_static_path();
	void  serve_file();
	void  serve_file();
	void  start();
	void  stop();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif