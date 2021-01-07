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
#include <hyobject.h>
#include <common.h>
#include <entity.h>

class api : public HyObject, public HyPluginInterface
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.nagyimre.HyperBorg.HyPluginInterface" FILE "api.json");
    Q_INTERFACES(HyPluginInterface);
public:
    api(QObject *parent=nullptr);
    ~api();

    QString name() 		{ return "api"; }
    QString description()	{ return "Rest API for Home Assistant."; }
    int implementation()	{ return NotImplemented; }

public slots:
    void init();

protected:
    	void setup();
	void forward_events();
	void post();
	void async_services_json();
	void async_events_json();

private:

    //HASS manifest. We keep those here to credit the original authors
    QHash<QString, QString> manifest;
};


#endif