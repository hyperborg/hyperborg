/* HyperBorg House Management System
   Using Qt 5.15 (opensource)
   (C)
*/

#ifndef API_H
#define API_H

#include <QObject>
#include <QString>
#include <QtPlugin>
#include <QString>
#include <QHash>

#include <hyplugin.h>

class api : public QObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "api.json");
    Q_INTERFACES(HyPluginInterface);
public:
    api();
    ~api();

    QString name() 		{ return "api"; }
    QString description()	{ return "Rest API for Home Assistant."; }

protected:
    	void setup();
	void get();
	void  get();
	void  forward_events();
	void get();
	void get();
	void get();
	void get();
	void  post();
	void delete();
	void get();
	void  post();
	void  get();
	void  post();
	void get();
	void  post();
	void  get();
	void  async_services_json();
	void async_events_json();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif